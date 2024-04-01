#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class User {
private:
    string username;
    int age;
public:
    User(string uname, int uage) : username(uname), age(uage) {}

    string getUsername() const {
        return username;
    }

    int getAge() const {
        return age;
    }
};

class UserList {
private:
    vector<User> users;
public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    void removeUser(const string& username) {
        auto it = find_if(users.begin(), users.end(), [&](const User& user) {
            return user.getUsername() == username;
        });

        if (it != users.end()) {
            users.erase(it);
            cout << "User " << username << " removed successfully.\n";
        } else {
            cout << "User " << username << " not found.\n";
        }
    }

    User* findUser(const std::string& username) {
        auto it = find_if(users.begin(), users.end(), [&](const User& user) {
            return user.getUsername() == username;
        });

        if (it != users.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }
};

int main()
{
    UserList userList;

    userList.addUser(User("user1", 25));
    userList.addUser(User("user2", 30));
    userList.addUser(User("user3", 22));

    userList.removeUser("user2");

    User* foundUser = userList.findUser("user1");
    if (foundUser != nullptr) {
        cout << "User found: " << foundUser->getUsername() << ", Age: " << foundUser->getAge() << endl;
    } else {
        cout << "User not found.\n";
    }

    return 0;
}
