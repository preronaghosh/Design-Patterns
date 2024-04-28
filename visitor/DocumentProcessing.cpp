#include<iostream>
#include<vector>
#include<memory>

// Forward declarations
class Paragraph;
class Header;
class Image;

// Visitor interface
class DocumentProcessor {
public:
    virtual void process(Paragraph& paragraph) = 0;
    virtual void process(Header& header) = 0;
    virtual void process(Image& image) = 0;
};

// Element interface
class DocumentElement {
public:
    virtual void accept(DocumentProcessor& processor) = 0;
};

// Concrete Element: Paragraph
class Paragraph : public DocumentElement {
public:
    void accept(DocumentProcessor& processor) override {
        processor.process(*this);
    }
};

// Concrete Element: Header
class Header : public DocumentElement {
public:
    void accept(DocumentProcessor& processor) override {
        processor.process(*this);
    }
};

// Concrete Element: Image
class Image : public DocumentElement {
public:
    void accept(DocumentProcessor& processor) override {
        processor.process(*this);
    }
};

// Concrete Visitor for spell checking on all types of documents
class SpellChecker : public DocumentProcessor {
public:
    void process(Paragraph& paragraph) override {
        std::cout << "Performing spell check on a paragraph" << std::endl;
    }

    void process(Header& header) override {
        std::cout << "Performing spell check on a header" << std::endl;
    }

    void process(Image& image) override {
        std::cout << "Images don't need spell checking!" << std::endl;
        // No implementation here
    }
};

// Concrete Visitor for converting all types of documents to HTML
class HtmlConverter : public DocumentProcessor {
public:
    void process(Paragraph& paragraph) override {
        std::cout << "Converting paragraph to HTML" << std::endl;
    }

    void process(Header& header) override {
        std::cout << "Converting header to HTML" << std::endl;
    }

    void process(Image& image) override {
        std::cout << "Converting image to HTML" << std::endl;
    }
};

int main() {
    // Create all concrete elements
    std::vector<std::unique_ptr<DocumentElement>> listOfElements;

    listOfElements.emplace_back(std::make_unique<Paragraph>());
    listOfElements.emplace_back(std::make_unique<Header>());
    listOfElements.emplace_back(std::make_unique<Image>());

    // Create all concrete visitors
    SpellChecker spellChecker;
    HtmlConverter htmlConv;

    std::cout << "Starting spell checking on all documents.." << std::endl;
    for(const auto& element : listOfElements) {
        element->accept(spellChecker);
    }

    std::cout << "------------------------------------------" << std::endl;

    std::cout << "Starting conversion of all documents to Html.." << std::endl;
    for(const auto& element : listOfElements) {
        element->accept(htmlConv);
    }

    return 0;
}