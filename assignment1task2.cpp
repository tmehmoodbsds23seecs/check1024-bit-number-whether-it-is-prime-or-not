// //Tahir Mehmood
// //458593
#include <iostream>
#include <random>

using namespace std;

// Node structure to store 64-bit parts of the large number
struct Node
{
    uint64_t value;
    Node *next;
    Node(uint64_t val) : value(val), next(nullptr) {}
};

// Linked list class to store 1024-bit number
class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Add a 64-bit chunk at the end of the list
    void append(uint64_t value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Get the value at a specific index
    uint64_t get(int index)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < index)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            throw out_of_range("Index out of bounds");
        }
        return temp->value;
    }

    // Print all the 64-bit chunks in the linked list
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

// Modular exponentiation (a^b mod m)
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t mod)
{
    uint64_t result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Miller-Rabin primality test
bool millerRabin(uint64_t n, int iterations)
{
    if (n < 2 || n % 2 == 0)
        return false;
    uint64_t d = n - 1;
    int r = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    for (int i = 0; i < iterations; i++)
    {
        uint64_t a = 2 + rand() % (n - 4);
        uint64_t x = modExp(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (int j = 0; j < r - 1; j++)
        {
            x = modExp(x, 2, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

int main()
{
    // Example 1024-bit number divided into 16 parts (64 bits each)
    LinkedList bigNumber;

    // Generate random 1024-bit number (16 chunks of 64 bits)
    random_device rd;
    mt19937_64 gen(rd());
    for (int i = 0; i < 16; i++)
    {
        uint64_t randomChunk = gen();
        bigNumber.append(randomChunk);
    }

    // Display the number chunks
    cout << "1024-bit number chunks (in 64-bit parts):\n";
    bigNumber.printList();

    // Assume the big number is stored as one large number in the list
    // Test the primality of the number stored in the first chunk for simplicity
    try
    {
        uint64_t testNumber = bigNumber.get(0); // Take first chunk for primality test

        if (millerRabin(testNumber, 5))
        {
            cout << "The number is probably prime.\n";
        }
        else
        {
            cout << "The number is composite.\n";
        }
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}