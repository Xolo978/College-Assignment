#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Book{
    char title[100];
    char author[100];
    int publicationYear;
    struct Book* next;
} Book;

typedef struct Genre{
    Book* books;
    char genreName[100];
    struct Genre *next; 
} Genre;

Book *createBookNode(char *title, char *author, int publicationYear){
    Book *newNode = (Book *)malloc(sizeof(Book));
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->publicationYear = publicationYear;
    newNode->next=NULL;
    return newNode;
}

void insertBookAtFront(Genre *genre, Book *newNode) {
    newNode->next = genre->books;
    genre->books = newNode;
}

void deleteBookFromFront(Genre *genre){
    if (genre->books == NULL){
        printf("\nThis genre is empty.");
    }
    Book *temp = genre->books;
    genre->books = temp->next;
    free(temp);
}

void displayBooks(Book *head){
    if (head == NULL){
        printf("\nNo books are added.");
        return;
    }
    Book *temp = head;
    while (temp!=NULL){
        printf("\nTitle: %s \nAuthor: %s \nYear: %d\n", temp->title, temp->author, temp->publicationYear);
        temp=temp->next;
    }
}

Genre *createGenreNode(char *genreName){
    Genre *newNode = (Genre *)malloc(sizeof(Genre));
    strcpy(newNode->genreName, genreName);
    newNode->books=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertGenreAtFront(Genre **head, Genre *newGenre){
    newGenre->next = *head;
    *head = newGenre;
}

void deleteGenreFromFront(Genre **head){
    Genre *temp = *head;
    if (temp == NULL){
        printf("\n No genre exists to be deleted.");
        return;
    }
    *head=temp->next;
    Book *btemp = temp->books;
    while(btemp){
        Book *temp2 = btemp;
        temp2=temp2->next;
        free(btemp);
    }
    free(temp);
}

void displayGenres(Genre *head) {
    if (head == NULL) {
        printf("\nNo genres in the library.");
        return;
    }
    Genre *temp = head;
    while (temp != NULL) {
        printf("\nGenre: %s\n", temp->genreName);
        displayBooks(temp->books);
        temp = temp->next;
    }
}

Book* searchBookByTitle(Genre *head, char *title, Genre **foundGenre) {
    Genre *gtemp = head;
    while (gtemp) {
        Book *btemp = gtemp->books;
        while (btemp) {
            if (strcmp(btemp->title, title) == 0) {
                *foundGenre = gtemp;
                return btemp;
            }
            btemp = btemp->next;
        }
        gtemp = gtemp->next;
    }
    return NULL;
}

void updateBookDetails(Genre *head, char *title) {
    Genre *foundGenre = NULL;
    Book *book = searchBookByTitle(head, title, &foundGenre);
    if (book == NULL) {
        printf("Book not found.\n");
        return;
    }
    printf("Book found under genre: %s\n", foundGenre->genreName);
    printf("Enter new author: ");
    scanf(" %[^\n]", book->author);
    printf("Enter new publication year: ");
    scanf("%d", &book->publicationYear);
    printf("Book details updated successfully!\n");
}

int main() {
    Genre *library = NULL;
    int choice;
    char genreName[100], title[100], author[100];
    int year;

    while (1) {
        printf("\n=== Library Catalog Management ===\n");
        printf("1. Add Genre\n");
        printf("2. Add Book to Genre\n");
        printf("3. Delete Genre from Front\n");
        printf("4. Delete Book from Genre (Front)\n");
        printf("5. Display All Genres & Books\n");
        printf("6. Search Book by Title\n");
        printf("7. Update Book Details\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter genre name: ");
                scanf(" %[^\n]", genreName);
                insertGenreAtFront(&library, createGenreNode(genreName));
                break;

            case 2:
                printf("Enter genre name to add book: ");
                scanf(" %[^\n]", genreName);
                {
                    Genre *gtemp = library;
                    while (gtemp && strcmp(gtemp->genreName, genreName) != 0)
                        gtemp = gtemp->next;
                    if (!gtemp) {
                        printf("Genre not found.\n");
                        break;
                    }
                    printf("Enter book title: ");
                    scanf(" %[^\n]", title);
                    printf("Enter author: ");
                    scanf(" %[^\n]", author);
                    printf("Enter publication year: ");
                    scanf("%d", &year);
                    insertBookAtFront(gtemp, createBookNode(title, author, year));
                }
                break;

            case 3:
                deleteGenreFromFront(&library);
                break;

            case 4:
                printf("Enter genre name to delete book: ");
                scanf(" %[^\n]", genreName);
                {
                    Genre *gtemp = library;
                    while (gtemp && strcmp(gtemp->genreName, genreName) != 0)
                        gtemp = gtemp->next;
                    if (!gtemp) {
                        printf("Genre not found.\n");
                        break;
                    }
                    deleteBookFromFront(gtemp);
                }
                break;

            case 5:
                displayGenres(library);
                break;

            case 6:
                printf("Enter book title to search: ");
                scanf(" %[^\n]", title);
                {
                    Genre *foundGenre = NULL;
                    Book *book = searchBookByTitle(library, title, &foundGenre);
                    if (book) {
                        printf("Found under genre: %s\nAuthor: %s\nYear: %d\n",
                               foundGenre->genreName, book->author, book->publicationYear);
                    } else {
                        printf("Book not found.\n");
                    }
                }
                break;

            case 7:
                printf("Enter book title to update: ");
                scanf(" %[^\n]", title);
                updateBookDetails(library, title);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}