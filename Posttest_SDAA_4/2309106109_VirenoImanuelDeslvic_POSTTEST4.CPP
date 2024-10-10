#include <iostream>
#include <limits>
using namespace std;

struct anime {
    string nama_anime;
    int jumlah_episode;
    string tipe_anime;
    string genre_anime;
    string studio_anime;
    string sinopsis_anime;
};

struct Node {
    anime data;
    Node* next;
    Node* prev;
};

struct StackNode {
    Node* animeNode;
    StackNode* next;
};

struct QueueNode {
    Node* animeNode;
    QueueNode* next;
};

class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}
    void push(Node* animeNode) {
        StackNode* newNode = new StackNode{ animeNode, top };
        top = newNode;
    }
    Node* pop() {
        if (top == nullptr) return nullptr;
        StackNode* temp = top;
        Node* animeNode = top->animeNode;
        top = top->next;
        delete temp;
        return animeNode;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

// Queue class
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(Node* animeNode) {
        QueueNode* newNode = new QueueNode{ animeNode, nullptr };
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    Node* dequeue() {
        if (front == nullptr) return nullptr;
        QueueNode* temp = front;
        Node* animeNode = front->animeNode;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return animeNode;
    }
    bool isEmpty() {
        return front == nullptr;
    }
};

Node* buatNode(anime data) {
    Node* nodeBaru = new Node;
    nodeBaru->data = data;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;
    return nodeBaru;
}

void menambahkan(Node*& head, Node*& tail) {
    anime animeBaru;

    cout << "\nMasukkan anime baru: ";
    cin.ignore();
    getline(cin, animeBaru.nama_anime);
    
    do {
        cout << "Masukkan jumlah episode: ";
        if (cin >> animeBaru.jumlah_episode) {
            break;
        } else {
            cout << "Inputan tidak valid, silahkan masukkan angka" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
    
    cin.ignore();
    cout << "TV/ONA/OVA/MOVIE/SPECIAL" << endl;
    cout << "Pilih tipe anime: ";
    cin >> animeBaru.tipe_anime;
    
    cout << "Action/Comedy/Romance/Fantasy/Adventure" << endl;
    cout << "Pilih genre anime: ";
    cin.ignore();
    getline(cin, animeBaru.genre_anime);
    
    cout << "Toei Animation/MAPPA/SILVER LINK/Kyoto Animation/Aniplex/Ufotable/Madhouse/Bones" << endl;
    cout << "Pilih studio anime: ";
    getline(cin, animeBaru.studio_anime);
    
    cout << "Masukkan sinopsis anime: ";
    getline(cin, animeBaru.sinopsis_anime);

    Node* nodeBaru = buatNode(animeBaru);
    
    if (head == nullptr) {
        head = nodeBaru;
        tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    cout << "Data berhasil ditambahkan\n" << endl;
}

void melihat(Node* head) {
    if (head == nullptr) {
        cout << "Data tidak ada!\n" << endl;
        return;
    }
    Node* newnode = head;  
    int index = 1;
    
    while (newnode != nullptr) {
        cout << "\n" << endl;
        cout << index << ". Nama anime: " << newnode->data.nama_anime << endl;
        cout << "Jumlah Episode: " << newnode->data.jumlah_episode << endl;
        cout << "Tipe anime: " << newnode->data.tipe_anime << endl;
        cout << "Genre anime: " << newnode->data.genre_anime << endl;
        cout << "Studio anime: " << newnode->data.studio_anime << endl;
        cout << "Sinopsis anime: " << newnode->data.sinopsis_anime << endl;
        newnode = newnode->next;
        index++;
    }
    cout << "\n" << endl;
}

void merubah(Node* head, int indeks) {
    if (head == nullptr) {
        cout << "Data tidak ada!\n" << endl;
        return;
    }
    Node* newnode = head;  
    int index = 1;
    
    while (newnode != nullptr && index < indeks) {
        newnode = newnode->next;
        index++;
    }
    
    if (newnode == nullptr) {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    int pilih_yang_ingin_diubah;
    do {
        cout << "\n1. Nama anime" << endl;
        cout << "2. Jumlah episode" << endl;
        cout << "3. Tipe anime" << endl;
        cout << "4. Genre anime" << endl;
        cout << "5. Studio anime" << endl;
        cout << "6. Sinopsis anime" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih yang ingin diubah: ";
        cin >> pilih_yang_ingin_diubah;

        switch (pilih_yang_ingin_diubah) {
            case 1:
                cout << "Masukkan nama anime baru: ";
                cin.ignore();
                getline(cin, newnode->data.nama_anime);  
                break;
            case 2:
                cout << "Masukkan jumlah episode baru: ";
                while (!(cin >> newnode->data.jumlah_episode)) {
                    cout << "Input tidak valid, silakan masukkan angka." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            case 3:
                cout << "Masukkan tipe baru: ";
                cin >> newnode->data.tipe_anime;
                break;
            case 4:
                cout << "Masukkan genre baru: ";
                cin.ignore();
                getline(cin, newnode->data.genre_anime);
                break;
            case 5:
                cout << "Masukkan studio baru: ";
                getline(cin, newnode->data.studio_anime);
                break;
            case 6:
                cout << "Masukkan sinopsis baru: ";
                getline(cin, newnode->data.sinopsis_anime);
                break;
            case 7:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih_yang_ingin_diubah != 7);
    cout << "Data berhasil diubah.\n" << endl;
}

void menghapus(Node*& head, Node*& tail, int indeks) {
    if (head == nullptr) {
        cout << "Data tidak ada!\n" << endl;
        return;
    }
    Node* newnode = head;  
    int index = 1;
    
    while (newnode != nullptr && index < indeks) {
        newnode = newnode->next;
        index++;
    }
    
    if (newnode == nullptr) {
        cout << "Indeks tidak valid." << endl;
        return;
    }

    if (newnode->prev != nullptr) {
        newnode->prev->next = newnode->next;
    } else {
        head = newnode->next;
    }

    if (newnode->next != nullptr) {
        newnode->next->prev = newnode->prev;
    } else {
        tail = newnode->prev;
    }

    delete newnode;  
    cout << "Data berhasil dihapus.\n" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    Stack animeStack;
    Queue animeQueue;
    int pilihan;

    do {
        cout << "== Menu utama ===" << endl;
        cout << "1. Menambahkan Anime" << endl;
        cout << "2. Melihat Data Anime" << endl;
        cout << "3. Mengubah Data Anime" << endl;
        cout << "4. Menghapus Data Anime" << endl;
        cout << "5. Tambah ke Stack" << endl;
        cout << "6. Tambah ke Queue" << endl;
        cout << "7. Ambil dari Stack" << endl;
        cout << "8. Ambil dari Queue" << endl;
        cout << "9. Program Berhenti" << endl;
        cout << "Silahkan pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menambahkan(head, tail);
                break;
            case 2:
                melihat(head);
                break;
            case 3: {
                int indeksUbah;
                cout << "Masukkan indeks data yang ingin diubah: ";
                cin >> indeksUbah;
                merubah(head, indeksUbah);
                break;
            }
            case 4: {
                int indeksHapus;
                cout << "Masukkan indeks data yang ingin dihapus: ";
                cin >> indeksHapus;
                menghapus(head, tail, indeksHapus);
                break;
            }
            case 5: {
                int index;
                cout << "Masukkan indeks anime yang ingin ditambahkan ke stack: ";
                cin >> index;
                Node* temp = head;
                for (int i = 1; i < index && temp != nullptr; i++) {
                    temp = temp->next;
                }
                if (temp) {
                    animeStack.push(temp);
                    cout << "Anime berhasil ditambahkan ke stack!" << endl;
                } else {
                    cout << "Indeks tidak valid." << endl;
                }
                break;
            }
            case 6: {
                int index;
                cout << "Masukkan indeks anime yang ingin ditambahkan ke queue: ";
                cin >> index;
                Node* temp = head;
                for (int i = 1; i < index && temp != nullptr; i++) {
                    temp = temp->next;
                }
                if (temp) {
                    animeQueue.enqueue(temp);
                    cout << "Anime berhasil ditambahkan ke queue!" << endl;
                } else {
                    cout << "Indeks tidak valid." << endl;
                }
                break;
            }
            case 7: {
                Node* animeNode = animeStack.pop();
                if (animeNode) {
                    cout << "Anime diambil dari stack: " << animeNode->data.nama_anime << endl;
                } else {
                    cout << "Stack kosong!" << endl;
                }
                break;
            }
            case 8: {
                Node* animeNode = animeQueue.dequeue();
                if (animeNode) {
                    cout << "Anime diambil dari queue: " << animeNode->data.nama_anime << endl;
                } else {
                    cout << "Queue kosong!" << endl;
                }
                break;
            }
            case 9:
                break;
            default:
                cout << "Input tidak valid.\n" << endl;
        }
    } while (pilihan != 9);
    
    return 0;
}
