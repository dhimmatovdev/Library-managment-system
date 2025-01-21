#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUM 100
#define MAXLENGTH 50

int num, i;
FILE *ptr = NULL;

// A'zolar uchun tuzilma
struct member {
    char memberName[MAXLENGTH];
    int memberID;
} membersList[MAXNUM];

// Kitoblar uchun tuzilma
struct books {
    char bookName[MAXLENGTH];
    char authorName[MAXLENGTH];
    int day, month, year;
} booksList[MAXNUM];

// Yangi a'zolarni ro'yxatdan o'tkazish
void registerMembers() {
    printf("Ro'yxatdan o'tkaziladigan a'zolar sonini kiriting: ");
    scanf("%d", &num);

    ptr = fopen("members.txt", "a");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("A'zoning ismini kiriting: ");
        scanf("%s", membersList[i].memberName);
        printf("A'zoning ID raqamini kiriting: ");
        scanf("%d", &membersList[i].memberID);
        printf("A'zo ismi: %s, A'zo ID: %d muvaffaqiyatli ro'yxatdan o'tdi.\n", membersList[i].memberName, membersList[i].memberID);
        fprintf(ptr, "%d. A'zo ismi: %s, A'zo ID: %d.\n", i + 1, membersList[i].memberName, membersList[i].memberID);
    }
    fclose(ptr);

    printf("A'zolar muvaffaqiyatli ro'yxatdan o'tdi. Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// Ro'yxatdan o'tgan a'zolarni ko'rish
void registeredMembers() {
    char line[256];

    ptr = fopen("members.txt", "r");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    printf("\nRo'yxatdan o'tgan a'zolar:\n");
    while (fgets(line, sizeof(line), ptr)) {
        printf("%s", line);
    }
    fclose(ptr);

    printf("Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// A'zolarni qidirish
void searchMembers() {
    char searchTerm[MAXLENGTH];
    char line[256];
    int found = 0;

    printf("A'zoning ismini yoki ID raqamini kiriting: ");
    scanf("%s", searchTerm);

    ptr = fopen("members.txt", "r");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    while (fgets(line, sizeof(line), ptr)) {
        if (strstr(line, searchTerm) != NULL) {
            printf("Topildi: %s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("Hozirgi so'z bilan a'zo topilmadi: %s\n", searchTerm);
    }

    fclose(ptr);
    printf("Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// Yangi kitoblarni ro'yxatdan o'tkazish
void registerBooks() {
    printf("Ro'yxatdan o'tkaziladigan kitoblar sonini kiriting: ");
    scanf("%d", &num);

    ptr = fopen("books.txt", "a");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Kitob nomini kiriting %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Muallif ismini kiriting: ");
        scanf("%s", booksList[i].authorName);
        printf("Chop etilgan sana (kun oy yil): ");
        scanf("%d %d %d", &booksList[i].day, &booksList[i].month, &booksList[i].year);
        printf("Kitob nomi: %s\n", booksList[i].bookName);
        printf("Muallif ismi: %s\n", booksList[i].authorName);
        printf("Chop etilgan sana: %d-%d-%d\n", booksList[i].day, booksList[i].month, booksList[i].year);

        fprintf(ptr, "%d. Kitob nomi: %s, Muallif: %s, Chop etilgan sana: %d-%d-%d\n", i + 1, booksList[i].bookName, booksList[i].authorName, booksList[i].day, booksList[i].month, booksList[i].year);
    }

    fclose(ptr);
    printf("Kitoblar muvaffaqiyatli ro'yxatdan o'tdi. Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// Kitoblarni olish
void checkoutBooks() {
    printf("Olmoqchi bo'lgan kitoblar sonini kiriting: ");
    scanf("%d", &num);

    ptr = fopen("checkoutBooks.txt", "a");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Kitob nomini kiriting %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Muallif ismini kiriting: ");
        scanf("%s", booksList[i].authorName);
        printf("%s kitobi muvaffaqiyatli olindi.\n", booksList[i].bookName);
        printf("Muallif ismi: %s\n", booksList[i].authorName);

        fprintf(ptr, "Kitob nomi: %s, Muallif: %s (Olindi)\n", booksList[i].bookName, booksList[i].authorName);
    }

    fclose(ptr);
    printf("Kitoblar muvaffaqiyatli olindi. Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// Kitoblarni qaytarish
void returnBooks() {
    printf("Qaytariladigan kitoblar sonini kiriting: ");
    scanf("%d", &num);

    ptr = fopen("returnBooks.txt", "a");
    if (ptr == NULL) {
        perror("Faylni ochishda xatolik.");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("Kitob nomini kiriting %d: ", i + 1);
        scanf("%s", booksList[i].bookName);
        printf("Muallif ismini kiriting: ");
        scanf("%s", booksList[i].authorName);
        printf("%s kitobi muvaffaqiyatli qaytarildi.\n", booksList[i].bookName);
        printf("Muallif ismi: %s\n", booksList[i].authorName);

        fprintf(ptr, "Kitob nomi: %s, Muallif: %s (Qaytarildi)\n", booksList[i].bookName, booksList[i].authorName);
    }

    fclose(ptr);
    printf("Kitoblar muvaffaqiyatli qaytarildi. Davom etish uchun istalgan tugmani bosing...");
    getchar();  // Tugma bosilishini kuting
}

// Asosiy menyu funktsiyasi
int main() {

    int choice = 1;  // Tanlovni boshlang

    while (choice != 0) {  // Chiqish sharti
        system("clear");  // Ekranni tozalash (Linuxda ishlaydi)

        printf("\nKutubxona Boshqaruv Tizimi\n");
        printf("1. Yangi A'zoni qo'shish\n");
        printf("2. A'zolarni ko'rish\n");
        printf("3. A'zolarni qidirish\n");
        printf("4. Yangi kitoblarni qo'shish\n");
        printf("5. Kitoblarni olish\n");
        printf("6. Kitoblarni qaytarish\n");
        printf("0. Chiqish\n");
        printf("Tanlovingizni kiriting: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerMembers();
                break;
            case 2:
                registeredMembers();
                break;
            case 3:
                searchMembers();
                break;
            case 4:
                registerBooks();
                break;
            case 5:
                checkoutBooks();
                break;
            case 6:
                returnBooks();
                break;
            case 0:
                printf("Chiqilyapti...\n");
                break;
            default:
                printf("Noto'g'ri tanlov. Davom etish uchun istalgan tugmani bosing...\n");
                getchar();
                break;
        }
    }

    return 0;
}
