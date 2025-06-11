# Лабораторная работа №1

_Последовательности и динамические массивы_

---

## Постановка задачи

Реализовать иерархию классов для представления линейных структур данных с использованием шаблонов.  
Система должна включать:
- абстрактный интерфейс `Sequence`
- конкретные реализации на основе динамического массива (`ArraySequence`)
- собственную реализацию динамического массива (`DynamicArray`)
- модульные тесты на основные операции

---

## Описание решения

### `DynamicArray<T>` — шаблонный динамический массив
```cpp
template<typename T>
class DynamicArray {
public:
    DynamicArray(int size);
    DynamicArray(const T* items, int count);
    DynamicArray(const DynamicArray<T>& other);

    T Get(int index) const;
    int GetSize() const;

    void Set(int index, T value);
    void Resize(int newSize);

    DynamicArray<T>& operator=(const DynamicArray<T>& other);
};
```

- `DynamicArray(size: int)`  
    > Создаёт массив заданного размера  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **size** — количество элементов

- `DynamicArray(items: const T*, count: int)`  
    > Создаёт массив из переданного указателя на элементы  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **items** — массив данных  
    >   * **count** — число элементов

- `DynamicArray(const DynamicArray& other)`  
    > Конструктор копирования  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **other** — другой массив

- `Get(index: int) const -> T`  
    > Возвращает элемент по индексу  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **index** — индекс элемента  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Копия элемента

- `GetSize() const -> int`  
    > Возвращает количество элементов  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Размер массива

- `Set(index: int, value: T)`  
    > Устанавливает значение по индексу  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **index** — индекс  
    >   * **value** — новое значение

- `Resize(newSize: int)`  
    > Изменяет размер массива  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **newSize** — новый размер

---

### `Sequence<T>` — абстрактный интерфейс последовательности
```cpp
template<typename T>
class Sequence {
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;

    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;

    virtual Sequence<T>* Clone() const = 0;

    virtual ~Sequence() = default;
};
```

- `GetFirst() const -> T`  
    > Возвращает первый элемент последовательности  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Первый элемент

- `GetLast() const -> T`  
    > Возвращает последний элемент  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Последний элемент

- `Get(index: int) const -> T`  
    > Возвращает элемент по индексу  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **index** — индекс  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Копия элемента

- `GetLength() const -> int`  
    > Возвращает длину последовательности  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Количество элементов

- `Append(item: const T&)`  
    > Добавляет элемент в конец  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **item** — значение для добавления

- `Prepend(item: const T&)`  
    > Добавляет элемент в начало  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **item** — значение для добавления

- `InsertAt(item: const T&, index: int)`  
    > Вставляет элемент по индексу  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **item** — значение  
    >   * **index** — позиция вставки

- `GetSubsequence(startIndex: int, endIndex: int) const -> Sequence<T>*`  
    > Возвращает подпоследовательность  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **startIndex** — начальный индекс  
    >   * **endIndex** — конечный индекс  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Указатель на новую подпоследовательность

- `Clone() const -> Sequence<T>*`  
    > Клонирует текущую последовательность  
    >
    > _ВОЗВРАЩАЕТ:_  
    >   * Новый объект `Sequence`

---

### `ArraySequence<T>` — реализация `Sequence` на основе `DynamicArray`
```cpp
template<typename T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence();
    ArraySequence(const T* items, int count);
    ArraySequence(const DynamicArray<T>& array);

    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    int GetLength() const override;

    void Append(const T& item) override;
    void Prepend(const T& item) override;
    void InsertAt(const T& item, int index) override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;

    Sequence<T>* Clone() const override;
};
```

- `ArraySequence()`  
    > Конструктор по умолчанию (пустая последовательность)

- `ArraySequence(items: const T*, count: int)`  
    > Конструктор из массива  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **items** — указатель на массив  
    >   * **count** — количество элементов

- `ArraySequence(array: const DynamicArray<T>&)`  
    > Конструктор из `DynamicArray`  
    >
    > _ПАРАМЕТРЫ:_  
    >   * **array** — динамический массив

_*описание всех override-методов аналогично интерфейсу `Sequence`_

---

## Тестирование

Для проверки корректности реализованы модульные тесты в файле `Tests.hpp`, охватывающие:

- граничные случаи работы с `DynamicArray` и `ArraySequence`
- добавление, вставку, удаление, получение элементов
- корректность `GetSubsequence()` и `Clone()`
