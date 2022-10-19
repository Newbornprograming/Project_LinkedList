#include <iostream>
#include <conio.h>

using namespace std;

struct Data
{
    //inisialisasi Kumpulan data berisi nilai x dan y
    int nilaiX;
    int nilaiY;
    //inisilaisasi pointer penunjuk pada linked list
    Data *next;
};
//deklarasi untuk menentukan head (data awal), tail (data ahkir)
// baru (simpul baru), bantu (untuk membantu pengecekan mencari data)
Data *head, *tail, *bantu, *baru, *bantu2;
//fungsi untuk menetukan apakah data kosong atau tidak
int jika_kosong()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//fungsi memasukan data dari depan atau head
void masuk_depan()
{
    baru = new Data;
    cout << "Masukkan nilai X : ";
    cin >> baru->nilaiX;
    cout << "Masukkan nilai Y : ";
    cin >> baru->nilaiY;
    baru->next = NULL;
    if (jika_kosong() == 1)
    {
        // jika data yang dimasukan baru 1 maka otomatis menjadi head dan tail
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        //jika data lebih dari 1
        baru->next = head;
        head = baru;
    }
    cout << "Data masuk ke bagian depan" << endl;
}
//memasukan data dari tengah, 
//fungsi ini dibagi menjadi 2 untuk setelah dan sebelum data
void masuk_tengah()
{
    int carix, cariy, barux, baruy;
    baru = new Data;
    cout << "Masukkan posisi data yang akan disisipkan : " << endl;
    cout << "1. Sebelum data yang akan disisipkan" << endl;
    cout << "2. Sesudah data yang akan disisipkan" << endl;
    int pilih;
    cin >> pilih;
    if (pilih == 1)
    {
        cout << "Masukkan nilai X yang akan disisipkan : ";
        cin >> carix;
        cout << "Masukkan nilai Y yang akan disisipkan : ";
        cin >> cariy;
        // mengecek apakah data X dan Y yang dicari harus ada 
        //jika salah satu ada yang tidak ditemukan maka hasilnya tdk ditemukan
        bantu = head;
        while (bantu != NULL)
        {
            if (bantu->nilaiX == carix && bantu->nilaiY == cariy)
            {
                cout << "Data ditemukan" << endl;
                cout << "Masukkan nilai X baru : ";
                cin >> barux;
                cout << "Masukkan nilai Y baru : ";
                cin >> baruy;
                baru->nilaiX = barux;
                baru->nilaiY = baruy;
                // proses sisipkan data jika data yang dicari ada di depan
                if (bantu == head)
                {
                    baru->next = head;
                    head = baru;
                }
                // proses sisipkan data jika data yang dicari ada di tengah
                else
                {
                    baru->next = bantu;
                    bantu2->next = baru;
                }
                cout << "Data berhasil disisipkan" << endl;
                break;
            }
            else
            {
                bantu2 = bantu;
                bantu = bantu->next;
            }
        }
        if (bantu == NULL)
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else if (pilih == 2)
    {
        cout << "Masukkan nilai X yang akan disisipkan : ";
        cin >> carix;
        cout << "Masukkan nilai Y yang akan disisipkan : ";
        cin >> cariy;
        // mengecek apakah data yang dicari ada atau tidak
        bantu = head;
        while (bantu != NULL)
        {
            if (bantu->nilaiX == carix && bantu->nilaiY == cariy)
            {
                cout << "Data ditemukan" << endl;
                cout << "Masukkan nilai X baru : ";
                cin >> barux;
                cout << "Masukkan nilai Y baru : ";
                cin >> baruy;
                baru->nilaiX = barux;
                baru->nilaiY = baruy;
                // proses sisipkan data jika data yang dicari ada di belakang
                if (bantu == tail)
                {
                    baru->next = NULL;
                    tail->next = baru;
                    tail = baru;
                }
                // proses sisipkan data jika data yang dicari ada di tengah
                else
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                cout << "Data berhasil disisipkan" << endl;
                break;
            }
            else
            {
                bantu = bantu->next;
            }
            
        }
        if (bantu == NULL)
            {
                cout << "Data tidak ditemukan" << endl;
            }
    }
    else
    {
        cout << "Pilihan tidak tersedia" << endl;
    }
}
void masuk_belakang()
{
    Data *baru;
    baru = new Data;
    cout << "Masukkan nilai X : ";
    cin >> baru->nilaiX;
    cout << "Masukkan nilai Y : ";
    cin >> baru->nilaiY;
    baru->next = NULL;
    if (jika_kosong() == 1)
    {
        head = baru;
        tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
    cout << "Data masuk ke belakang" << endl;
}
void hapus_depan()
{
    Data *hapus;
    int d;
    if (jika_kosong() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        cout << "Data terdepan terhapus" << endl;
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}
void hapus_tengah()
{
    Data *hapus, *bantu, *bantu2;
    int carix, cariy;
    if (jika_kosong() == 0)
    {
        cout << "Masukkan nilai X yang akan dihapus : ";
        cin >> carix;
        cout << "Masukkan nilai Y yang akan dihapus : ";
        cin >> cariy;
        bantu = head;
        while (bantu->nilaiX != carix && bantu->nilaiY != cariy)
        {
            //bantu 2 adalah simpul sebelum simpul yang dicari
            bantu2 = bantu;
            bantu = bantu->next;
        }
        if (bantu->nilaiX == carix && bantu->nilaiY == cariy)
        {
            if (bantu == head)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else if (bantu == tail)
            {
                hapus = tail;
                tail = bantu2;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                bantu2->next = bantu->next;
                delete bantu;
            }
            cout << "Data berhasil dihapus" << endl;
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}
void hapus_belakang()
{
    Data *hapus, *bantu;
    if (jika_kosong() == 0)
    {
        if (head->next != NULL)
        {
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            hapus = tail;
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        cout << "Data terbelakang terhapus" << endl;
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}
void mencari_data()
{
    Data *bantu;
    int carix, cariy;
    if (jika_kosong() == 0)
    {
        cout << "Masukkan nilai X yang akan dicari : ";
        cin >> carix;
        cout << "Masukkan nilai Y yang akan dicari : ";
        cin >> cariy;
        bantu = head;
        while (bantu->nilaiX != carix && bantu->nilaiY != cariy)
        {
            bantu = bantu->next;
        }
        if (bantu->nilaiX == carix && bantu->nilaiY == cariy)
        {
            cout << "Data ditemukan" << endl;
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}
void tampil_data()
{
    Data *bantu;
    bantu = head;
    if (jika_kosong() == 0)
    {
        int angka = 1;
        while (bantu != NULL)
        {
            cout << angka << ". " << bantu->nilaiX << " " << bantu->nilaiY << endl;
            bantu = bantu->next;
            angka++;
        }
    }
    else
    {
        cout << "Data masih kosong" << endl;
    }
}
int main()
{
    int pilih;
    do
    {
        system("cls");
        tampil_data();
        cout << "1. Masukkan data ke depan" << endl;
        cout << "2. Masukkan data yang tertentu" << endl;
        cout << "3. Masukkan data ke belakang" << endl;
        cout << "4. Hapus data terdepan" << endl;
        cout << "5. Hapus data tertentu" << endl;
        cout << "6. Hapus data terbelakang" << endl;
        cout << "7. Mencari data" << endl;
        cout << "8. Menampilkan data" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            masuk_depan();
            getch();
            break;
        case 2:
            masuk_tengah();
            getch();
            break;
        case 3:
            masuk_belakang();
            getch();
            break;
        case 4:
            hapus_depan();
            getch();
            break;
        case 5:
            hapus_tengah();
            getch();
            break;
        case 6:
            hapus_belakang();
            getch();
            break;
        case 7:
            mencari_data();
            getch();
            break;
        case 8:
            tampil_data();
            getch();
            break;
        case 9:
            cout << "Terima kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
        }

    } while (pilih != 9);
    return 0;
}