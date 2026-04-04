// ===== SpendingTracker.pro =====
QT       += core gui widgets

TARGET = SpendingTracker
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           expense.cpp 

HEADERS += mainwindow.h \
           expense.h

FORMS += mainwindow.ui

// ===== main.cpp =====
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

// ===== expense.h =====
#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>

struct Expense {
    QString date;
    QString category;
    QString description;
    double amount;
    QString mode;
    QString needWant;

    QString toCsv() const;
    static Expense fromCsv(const QString &line);
};

#endif // EXPENSE_H

// ===== expense.cpp =====
#include "expense.h"
#include <QStringList>

QString Expense::toCsv() const {
    // escape commas in description by replacing with ';' (simple)
    QString desc = description;
    desc.replace(',', ';');
    return date + "," + category + "," + desc + "," + QString::number(amount, 'f', 2) + "," + mode + "," + needWant;
}

Expense Expense::fromCsv(const QString &line) {
    Expense e;
    QStringList parts = line.split(',');
    if (parts.size() >= 6) {
        e.date = parts[0];
        e.category = parts[1];
        e.description = parts[2];
        e.amount = parts[3].toDouble();
        e.mode = parts[4];
        e.needWant = parts[5];
    }
    return e;
}

// ===== mainwindow.h =====
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "expense.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_exportCsvButton_clicked();
    void on_table_itemSelectionChanged();
    void on_categoryFilter_currentIndexChanged(const QString &);
    void updateTotals();

private:
    Ui::MainWindow *ui;
    QVector<Expense> expenses;
    void refreshTable();
    void loadFromFile(const QString &filename);
    void saveToFile(const QString &filename);
};

#endif // MAINWINDOW_H

// ===== mainwindow.cpp =====
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configure table
    ui->table->setColumnCount(6);
    QStringList headers = {"Date", "Category", "Description", "Amount (₹)", "Mode", "Need/Want"};
    ui->table->setHorizontalHeaderLabels(headers);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connect signals
    connect(ui->table, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_table_itemSelectionChanged);

    // Load existing data (if any)
    loadFromFile("expenses.txt");
    refreshTable();
    updateTotals();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    Expense e;
    e.date = ui->dateEdit->text();
    e.category = ui->categoryEdit->currentText();
    e.description = ui->descriptionEdit->text();
    e.amount = ui->amountEdit->value();
    e.mode = ui->modeEdit->currentText();
    e.needWant = ui->needWantEdit->currentText();

    expenses.append(e);
    refreshTable();
    updateTotals();
}

void MainWindow::on_deleteButton_clicked() {
    auto rows = ui->table->selectionModel()->selectedRows();
    if (rows.empty()) {
        QMessageBox::information(this, "Delete", "Select a row to delete");
        return;
    }
    // remove in reverse order
    QVector<int> rowIndexes;
    for (const QModelIndex &m : rows) rowIndexes.append(m.row());
    std::sort(rowIndexes.begin(), rowIndexes.end(), std::greater<int>());
    for (int r : rowIndexes) {
        // find actual index in expenses by date+desc+amount match
        if (r >= 0 && r < expenses.size()) expenses.removeAt(r);
    }
    refreshTable();
    updateTotals();
}

void MainWindow::on_saveButton_clicked() {
    saveToFile("expenses.txt");
    QMessageBox::information(this, "Save", "Saved to expenses.txt");
}

void MainWindow::on_loadButton_clicked() {
    loadFromFile("expenses.txt");
    refreshTable();
    updateTotals();
    QMessageBox::information(this, "Load", "Loaded from expenses.txt");
}

void MainWindow::on_exportCsvButton_clicked() {
    QString file = QFileDialog::getSaveFileName(this, "Export CSV", "expenses_export.csv", "CSV Files (*.csv)");
    if (file.isEmpty()) return;
    saveToFile(file);
    QMessageBox::information(this, "Export", QString("Exported to %1").arg(file));
}

void MainWindow::on_table_itemSelectionChanged() {
    // Enable/disable delete button
    ui->deleteButton->setEnabled(!ui->table->selectionModel()->selectedRows().empty());
}

void MainWindow::on_categoryFilter_currentIndexChanged(const QString &cat) {
    Q_UNUSED(cat);
    refreshTable();
    updateTotals();
}

void MainWindow::refreshTable() {
    ui->table->setRowCount(0);
    QString filter = ui->categoryFilter->currentText();
    for (int i = 0; i < expenses.size(); ++i) {
        const Expense &e = expenses.at(i);
        if (filter != "All" && !filter.isEmpty() && e.category != filter) continue;
        int row = ui->table->rowCount();
        ui->table->insertRow(row);
        ui->table->setItem(row, 0, new QTableWidgetItem(e.date));
        ui->table->setItem(row, 1, new QTableWidgetItem(e.category));
        ui->table->setItem(row, 2, new QTableWidgetItem(e.description));
        ui->table->setItem(row, 3, new QTableWidgetItem(QString::number(e.amount, 'f', 2)));
        ui->table->setItem(row, 4, new QTableWidgetItem(e.mode));
        ui->table->setItem(row, 5, new QTableWidgetItem(e.needWant));
    }
}

void MainWindow::updateTotals() {
    double total = 0.0;
    QMap<QString, double> catTotals;
    QString filter = ui->categoryFilter->currentText();
    for (const Expense &e : expenses) {
        if (filter != "All" && !filter.isEmpty() && e.category != filter) continue;
        total += e.amount;
        catTotals[e.category] += e.amount;
    }
    ui->totalLabel->setText(QString("Total: ₹ %1").arg(QString::number(total, 'f', 2)));

    // Update category totals list widget
    ui->categoryList->clear();
    for (auto it = catTotals.begin(); it != catTotals.end(); ++it) {
        ui->categoryList->addItem(QString("%1 : ₹ %2").arg(it.key()).arg(QString::number(it.value(), 'f', 2)));
    }
}

void MainWindow::loadFromFile(const QString &filename) {
    expenses.clear();
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        Expense e = Expense::fromCsv(line);
        expenses.append(e);
    }
    f.close();

    // Populate category filter with unique categories
    QSet<QString> cats;
    for (const Expense &e : expenses) cats.insert(e.category);
    ui->categoryFilter->clear();
    ui->categoryFilter->addItem("All");
    for (const QString &c : cats) ui->categoryFilter->addItem(c);
}

void MainWindow::saveToFile(const QString &filename) {
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&f);
    for (const Expense &e : expenses) {
        out << e.toCsv() << "\n";
    }
    f.close();
}

// ===== mainwindow.ui =====
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>900</width>
    <height>600</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Spending Tracker</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <layout class="QVBoxLayout" name="verticalLayout">
    <item>
     <layout class="QHBoxLayout" name="inputLayout">
      <item>
       <widget class="QLineEdit" name="dateEdit">
        <property name="placeholderText"><string>DD-MM-YYYY</string></property>
       </widget>
      </item>
      <item>
       <widget class="QComboBox" name="categoryEdit">
        <item><property name="text"><string>Food</string></property></item>
        <item><property name="text"><string>Travel</string></property></item>
        <item><property name="text"><string>College</string></property></item>
        <item><property name="text"><string>Shopping</string></property></item>
        <item><property name="text"><string>Health</string></property></item>
        <item><property name="text"><string>Entertainment</string></property></item>
        <item><property name="text"><string>Other</string></property></item>
       </widget>
      </item>
      <item>
       <widget class="QLineEdit" name="descriptionEdit">
        <property name="placeholderText"><string>Description</string></property>
       </widget>
      </item>
      <item>
       <widget class="QDoubleSpinBox" name="amountEdit">
        <property name="maximum"><double>1000000.000000000000000</double></property>
        <property name="prefix"><string>₹ </string></property>
       </widget>
      </item>
      <item>
       <widget class="QComboBox" name="modeEdit">
        <item><property name="text"><string>Cash</string></property></item>
        <item><property name="text"><string>UPI</string></property></item>
        <item><property name="text"><string>Card</string></property></item>
       </widget>
      </item>
      <item>
       <widget class="QComboBox" name="needWantEdit">
        <item><property name="text"><string>Need</string></property></item>
        <item><property name="text"><string>Want</string></property></item>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="addButton">
        <property name="text"><string>Add</string></property>
       </widget>
      </item>
     </layout>
    </item>
    <item>
     <widget class="QTableWidget" name="table">
      <property name="minimumSize">
       <size>
        <width>600</width>
        <height>200</height>
       </size>
      </property>
     </widget>
    </item>
    <item>
     <layout class="QHBoxLayout" name="bottomLayout">
      <item>
       <widget class="QPushButton" name="deleteButton">
        <property name="text"><string>Delete</string></property>
        <property name="enabled"><bool>false</bool></property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="saveButton">
        <property name="text"><string>Save</string></property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="loadButton">
        <property name="text"><string>Load</string></property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="exportCsvButton">
        <property name="text"><string>Export CSV</string></property>
       </widget>
      </item>
      <item>
       <widget class="QComboBox" name="categoryFilter">
        <item><property name="text"><string>All</string></property></item>
       </widget>
      </item>
      <item>
       <widget class="QLabel" name="totalLabel">
        <property name="text"><string>Total: ₹ 0.00</string></property>
       </widget>
      </item>
     </layout>
    </item>
    <item>
     <widget class="QListWidget" name="categoryList">
      <property name="minimumHeight"><number>80</number></property>
     </widget>
    </item>
   </layout>
  </widget>
 </widget>
 <resources/>
 <connections>
  <connection>
   <sender>addButton</sender>
   <signal>clicked()</signal>
   <receiver>MainWindow</receiver>
   <slot>on_addButton_clicked()</slot>
  </connection>
  <connection>
   <sender>deleteButton</sender>
   <signal>clicked()</signal>
   <receiver>MainWindow</receiver>
   <slot>on_deleteButton_clicked()</slot>
  </connection>
  <connection>
   <sender>saveButton</sender>
   <signal>clicked()</signal>
   <receiver>MainWindow</receiver>
   <slot>on_saveButton_clicked()</slot>
  </connection>
  <connection>
   <sender>loadButton</sender>
   <signal>clicked()</signal>
   <receiver>MainWindow</receiver>
   <slot>on_loadButton_clicked()</slot>
  </connection>
  <connection>
   <sender>exportCsvButton</sender>
   <signal>clicked()</signal>
   <receiver>MainWindow</receiver>
   <slot>on_exportCsvButton_clicked()</slot>
  </connection>
  <connection>
   <sender>categoryFilter</sender>
   <signal>currentIndexChanged(QString)</signal>
   <receiver>MainWindow</receiver>
   <slot>on_categoryFilter_currentIndexChanged(QString)</slot>
  </connection>
 </connections>
</ui>

// ===== README =====
SpendingTracker - Qt (Widgets) C++ App

Features implemented:
- Add / Delete expenses
- Save & Load to expenses.txt (CSV-like)
- Export CSV
- Category filter and category totals
- Total amount display

How to build & run:
1. Install Qt (Qt 5 or Qt 6) and Qt Creator.
2. Open `SpendingTracker.pro` in Qt Creator.
3. Run qmake and build the project.
4. Run the application. The app saves data to `expenses.txt` in the working directory.

Notes & next steps:
- You can improve CSV escaping or switch to JSON (Qt's QJsonDocument).
- Add Edit dialog for updating existing expense rows.
- Add charts using Qt Charts library for monthly graphs.

Enjoy! If you want, I can now add an Edit dialog, persistent settings, or convert this to a cross-platform Electron/React GUI.