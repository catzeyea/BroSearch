#include <QMainWindow>
#include <QLineEdit> // Für die Eingabe

class MyWindow : public QMainWindow {
    Q_OBJECT // Wichtig! Ermöglicht Signals & Slots

public:
    explicit MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private slots: // Hier definierst du deine Empfänger-Funktion (Slots)
    void processInput();

private:
    QLineEdit *inputField; // Das moderne Eingabefeld
};