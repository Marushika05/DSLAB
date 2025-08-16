// 4) String Related Programs
// (a) Concatenate one string to another string
// (b) Reverse a string
// (c) Delete all vowels from a string
// (d) Sort characters of a string in alphabetical order
// (e) Convert characters from uppercase to lowercase (handled in vowels removal)

#include <iostream>
#include <string>   // for std::string operations
#include <cstring>  // for C-style string functions: strcat, strlen, strcpy
#include <cctype>   // for tolower
using namespace std;

class Strings {
    int i; 
    int n;

public:
    // Part (a) - Concatenate using string
    void concat1() {
        string s1 = "hello";
        string s2 = " world";

        // Method 1: Using + operator
        string result = s1 + s2;
        cout << "Concatenated (using +): " << result << endl;

        // Method 2: Using append()
        s1.append(s2);
        cout << "Concatenated (using append): " << s1 << endl;
    }

    // Part (a) - Concatenate using C-style strings
    void concat2() {
        char s1[50] = "good";
        char s2[50] = " morning";

        strcat(s1, s2);  // append s2 to s1
        cout << "Concatenated C-style string: " << s1 << endl;
    }

    // Part (b) - Reverse a string
    void reverse(char str[]) {
        int len = strlen(str);
        int n = len;

        // Swap characters from both ends
        for (i = 0; i < len / 2; i++) {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }

        cout << "Reversed string: " << str << endl;
    }

    // Part (c) - Remove vowels from a string (also demonstrates tolower usage)
    void removeVowels(char name[]) {
        int len = strlen(name);
        int j = 0; // index for writing non-vowel characters

        for (int i = 0; i < len; i++) {
            char ch = tolower(name[i]);
            if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
                name[j++] = name[i];  // keep non-vowel character
            }
        }

        name[j] = '\0'; // terminate the new string
        cout << "String without vowels: " << name << endl;
    }

    // Part (d) - Sort characters of a string alphabetically
    void order(char ord[]) {
        int len = strlen(ord);

        // Bubble sort characters
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (ord[j] > ord[j + 1]) {
                    char temp = ord[j];
                    ord[j] = ord[j + 1];
                    ord[j + 1] = temp;
                }
            }
        }

        cout << "Sorted string: " << ord << endl;
    }
};

int main() {
    Strings str1;
    char arr[100];  // string to reverse
    char name[100]; // string to remove vowels from
    char ord[100];  // string to sort alphabetically

    // Input for reverse
    cout << "Enter a string you want to reverse: ";
    cin.getline(arr, 100);

    // Input for vowels removal
    cout << "Enter a string to remove vowels from: ";
    cin.getline(name, 100);

    // Input for sorting
    cout << "Enter a string to sort alphabetically: ";
    cin.getline(ord, 100);

    // Call class functions
    str1.concat1();
    str1.concat2();
    str1.reverse(arr);
    str1.removeVowels(name);
    str1.order(ord);

    return 0;
}
