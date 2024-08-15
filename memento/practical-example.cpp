#include <iostream>
#include <string>
#include <stack>

// Memento: Stores the state of the TextEditor
class Memento {
public:
    Memento(const std::string& state) : state(state) {}
    std::string getState() const {
        return state;
    }

private:
    std::string state;
};

// Originator: The TextEditor whose state needs to be saved and restored
class TextEditor {
public:
    void type(const std::string& words) {
        content += words;
    }

    std::string getContent() const {
        return content;
    }

    Memento save() {
        return Memento(content);
    }

    void restore(const Memento& memento) {
        content = memento.getState();
    }

private:
    std::string content;
};

// Caretaker: Manages the memento and can request a restore
class History {
public:
    void save(const Memento& memento) {
        history.push(memento);
    }

    Memento undo() {
        if (history.empty()) {
            return Memento(""); // Return an empty state if no history is present
        }
        Memento memento = history.top();
        history.pop();
        return memento;
    }

private:
    std::stack<Memento> history;
};

int main() {
    TextEditor editor;
    History history;

    editor.type("Hello, ");
    history.save(editor.save());

    editor.type("world!");
    history.save(editor.save());

    std::cout << "Current Content: " << editor.getContent() << std::endl;

    editor.restore(history.undo());
    std::cout << "After undo: " << editor.getContent() << std::endl;

    editor.restore(history.undo());
    std::cout << "After undo: " << editor.getContent() << std::endl;

    return 0;
}
