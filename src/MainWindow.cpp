#include "MainWindow.hpp"
#include <QVBoxLayout> // Für modernes Layout
#include <QWidget>
#include <QDebug>    // Zum Ausgeben in der Konsole

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent) {
    // 1. Widget erstellen und Layout setzen (damit es modern aussieht)
    inputField = new QLineEdit(this);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Style für das Hauptfenster
    centralWidget->setStyleSheet(
        "QWidget { background-color: #2b2b2b; }"  // Dunkler Hintergrund
        "QLineEdit { "
        "   background-color: #3b3b3b; "          // Dunkelgrauer Hintergrund für das Eingabefeld
        "   color: #ffffff; "                     // Weiße Schrift
        "   border: 2px solid #4b4b4b; "         // Graue Umrandung
        "   border-radius: 5px; "                // Abgerundete Ecken
        "   padding: 5px; "                      // Innenabstand
        "   font-size: 14px; "                   // Schriftgröße
        "}"
    );
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(inputField);
    

    // 2. SIGNAL und SLOT verbinden
    connect(
        inputField, 
        &QLineEdit::returnPressed, // Das Signal
        this, 
        &MyWindow::processInput    // Dein Slot
    );
}

void MyWindow::processInput() {
    // 3. Im Slot den Text vom Eingabefeld abrufen
    QString inputText = inputField->text(); 
    
    // HIER kommt deine "Weiterverarbeitung" hin
    qDebug() << "Text verarbeitet:" << inputText;
    
   
    // Optional: Eingabefeld leeren
    inputField->clear(); 
}

MyWindow::~MyWindow() {} // Standad-Destruktor