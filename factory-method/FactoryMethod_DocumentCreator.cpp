#include <iostream>
#include <string>

// Product (Document)
class Document {
public:
    virtual void open() const = 0;
    virtual void save() const = 0;
    virtual ~Document() = default;
};

// Concrete Products (PDFDocument and WordDocument)
class PDFDocument : public Document {
public:
    void open() const override {
        std::cout << "Opening PDF document." << std::endl;
    }

    void save() const override {
        std::cout << "Saving PDF document." << std::endl;
    }
};

class WordDocument : public Document {
public:
    void open() const override {
        std::cout << "Opening Word document." << std::endl;
    }

    void save() const override {
        std::cout << "Saving Word document." << std::endl;
    }
};

// Creator (DocumentCreator - Factory Interface)
class DocumentCreator {
public:
    virtual Document* createDocument() const = 0;
    virtual ~DocumentCreator() = default;
};

// Concrete Creators (PDFDocumentCreator and WordDocumentCreator)
class PDFDocumentCreator : public DocumentCreator {
public:
    Document* createDocument() const override {
        return new PDFDocument();
    }
};

class WordDocumentCreator : public DocumentCreator {
public:
    Document* createDocument() const override {
        return new WordDocument();
    }
};

// class to encapsulate ony creation logic
class AnyDocCreator : public DocumentCreator {
public:
    explicit AnyDocCreator(const int type) : _type{type} {}
    
    Document* createDocument() const override {
        if (_type == 1) {
            return new WordDocument();
        } else {
            return new PDFDocument();
        }
    }   

private:
    int _type; // 1 - create word, else - create pdf
};

// Client Code
void clientCode(const DocumentCreator& creator) {
    Document* document = creator.createDocument();
    document->open();
    document->save();
    delete document;
}

int main() {
    // Using PDF Document Creator
    PDFDocumentCreator pdfCreator;
    std::cout << "Creating and working with PDF document:" << std::endl;
    clientCode(pdfCreator);

    std::cout << "Creating and working with Word document:" << std::endl;
    // Using Word Document Creator
    WordDocumentCreator wordCreator;
    clientCode(wordCreator);

    std::cout << "Creating and working with Word document:" << std::endl;
    AnyDocCreator docCreator1(1);
    clientCode(docCreator1);

    std::cout << "Creating and working with PDF document:" << std::endl;
    AnyDocCreator docCreator2(2);
    clientCode(docCreator2);

    return 0;
}
