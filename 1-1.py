def add_x(list,x,pos):
    a=list[:pos]
    b=list[pos:]
    a.append(x)
    return a + b

def binary_search(list,key):
    min = 0
    max = len(list)-1
    while min <= max:
        mid = (min + max)//2
        midValue = list[mid]
        if midValue == key:
            return f'Позиция данного элемента: {mid}'
        if midValue > key:
            max = mid - 1
        else:
            min = mid + 1
    ans=add_x(list,key,max+1)
    return f'Элемент не найден, но его можно вставить на позицию {max+1}, тогда итоговый массив будет выглядеть так: {ans}'

a=list(map(int,input("Введите массив, отделяя каждый элемент пробелом: ").split()))
x=int(input("Введите элемент, который требуется найти: "))
print(binary_search(a,x))

