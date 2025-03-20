#include <iostream>
#include "Authenticator.hpp"
#include "User.hpp"
#include "AdminUser.hpp"

using namespace std;

int main() {
    // Create an Authenticator instance
    Authenticator auth;

    // Register some users
    cout << "Registering users...\n";
    auth.registerUser("user1", "password1", false);  // Regular User
    auth.registerUser("admin1", "adminpassword", true);  // Admin User
    auth.registerUser("user2", "password2", false);  // Regular User

    // Try to register a user with an existing username
    cout << "\nAttempting to register with an existing username...\n";
    auth.registerUser("user1", "password3", false);

    // Try to register when the capacity is full
    cout << "\nAttempting to register after reaching the max capacity...\n";
    for (int i = 0; i < MAX_USERS - 3; i++) {
        auth.registerUser("user" + to_string(i + 3), "password", false);
    }

    // Try logging in with correct credentials
    cout << "\nLogging in with correct credentials...\n";
    auth.login("user1", "password1");
    auth.login("admin1", "adminpassword");

    // Try logging in with incorrect credentials
    cout << "\nLogging in with incorrect credentials...\n";
    auth.login("user1", "wrongpassword");

    // Access resource
    cout << "\nAccessing resource...\n";
    auth.accessResource();

    // Log out and try accessing resource again
    cout << "\nLogging out...\n";
    auth.logout();
    auth.accessResource();

    // Admin changes the resource
    cout << "\nAdmin trying to change the resource...\n";
    auth.setResource("This is the new secret resource!");
    
    // Try non-admin changing the resource
    cout << "\nNon-admin trying to change the resource...\n";
    auth.login("user1", "password1");
    auth.setResource("This is the new secret resource for regular users!");

    // Log out and try again
    cout << "\nLogging out again...\n";
    auth.logout();

    return 0;
}
