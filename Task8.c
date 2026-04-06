#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicList;

// Инициализация списка
void initList(DynamicList *list, int capacity) {
    list->data = (int*)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
}

// Освобождение памяти
void freeList(DynamicList *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

// Добавление элемента
void addElement(DynamicList *list) {
    if (list->size >= list->capacity) {
        int newCapacity = list->capacity * 2;
        int *tmp = (int*)realloc(list->data, newCapacity * sizeof(int));
        if (tmp == NULL) {
            printf("Ошибка выделения памяти!\n");
            return;
        }
        list->data = tmp;
        list->capacity = newCapacity;
        printf("Размер увеличен до %d\n", list->capacity);
    }
    
    int value;
    printf("Введите значение: ");
    scanf("%d", &value);
    list->data[list->size++] = value;
    printf("Элемент %d добавлен (всего: %d/%d)\n", value, list->size, list->capacity);
}

// Удаление элемента по индексу
void deleteElement(DynamicList *list) {
    if (list->size == 0) {
        printf("Список пуст! Нечего удалять.\n");
        return;
    }
    
    int index;
    printf("Введите индекс для удаления (0-%d): ", list->size - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= list->size) {
        printf("Неверный индекс!\n");
        return;
    }
    
    int deleted = list->data[index];
    
    // Сдвиг влево
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    
    // Оптимизация: если размер стал слишком мал, уменьшаем capacity
    if (list->size > 0 && list->size <= list->capacity / 4) {
        int newCapacity = list->capacity / 2;
        int *tmp = (int*)realloc(list->data, newCapacity * sizeof(int));
        if (tmp != NULL) {
            list->data = tmp;
            list->capacity = newCapacity;
            printf("Размер уменьшен до %d\n", list->capacity);
        }
    }
    
    printf("Элемент %d удален (осталось: %d/%d)\n", deleted, list->size, list->capacity);
}

// Вывод списка
void printList(DynamicList *list) {
    if (list->size == 0) {
        printf("Список пуст\n");
        return;
    }
    
    printf("Список (%d/%d): ", list->size, list->capacity);
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// Изменение размера массива (ручное)
void changeSize(DynamicList *list) {
    int newSize;
    printf("Введите новый размер (количество элементов): ");
    scanf("%d", &newSize);
    
    if (newSize < 0) {
        printf("Неверный размер!\n");
        return;
    }
    
    int *tmp = (int*)realloc(list->data, newSize * sizeof(int));
    if (tmp == NULL && newSize > 0) {
        printf("Ошибка выделения памяти!\n");
        return;
    }
    
    list->data = tmp;
    
    // Если новый размер меньше текущего, обрезаем
    if (newSize < list->size) {
        list->size = newSize;
    }
    
    list->capacity = newSize;
    printf("Размер изменен на %d (текущее количество: %d)\n", newSize, list->size);
}

int main() {
    DynamicList list;
    int initialCapacity;
    
    printf("Введите начальную длину массива: ");
    scanf("%d", &initialCapacity);
    
    if (initialCapacity <= 0) initialCapacity = 2;
    
    initList(&list, initialCapacity);
    
    int choice;
    
    do {
        printf("\n--МЕНЮ--\n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Вывести список\n");
        printf("4. Изменить размер массива\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addElement(&list);
                break;
            case 2:
                deleteElement(&list);
                break;
            case 3:
                printList(&list);
                break;
            case 4:
                changeSize(&list);
                break;
            case 0:
                printf("Выход из программы...\n");
                break;
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 0);
    
    freeList(&list);
    printf("Память освобождена. До свидания!\n");
    
    return 0;
}