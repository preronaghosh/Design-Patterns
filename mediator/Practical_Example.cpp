#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class ChatRoom;

class User {
public:
    User(const std::string& name) : name(name), chatRoom(nullptr) {}

    void sendMessage(const std::string& message) {
        if (chatRoom) {
            chatRoom->showMessage(this, message);
        }
    }

    void receiveMessage(const std::string& from, const std::string& message) {
        std::cout << from << " to " << name << ": " << message << std::endl;
    }

    void setChatRoom(ChatRoom* room) {
        chatRoom = room;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
    ChatRoom* chatRoom;
};

class ChatRoom {
public:
    void addUser(User* user) {
        user->setChatRoom(this);
        users.push_back(user);
    }

    void showMessage(User* sender, const std::string& message) {
        for (User* user : users) {
            if (user != sender) {
                user->receiveMessage(sender->getName(), message);
            }
        }
    }

private:
    std::vector<User*> users;
};

int main() {
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");

    ChatRoom chatRoom;
    chatRoom.addUser(&alice);
    chatRoom.addUser(&bob);
    chatRoom.addUser(&charlie);

    alice.sendMessage("Hello, everyone!");
    bob.sendMessage("Hi Alice!");

    return 0;
}
