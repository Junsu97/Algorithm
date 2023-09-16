def partition(start, end, array):
      
    pivot_index = start 
    pivot = array[pivot_index]
    print(pivot)
    while start < end:
        while start < len(array) and array[start] <= pivot:
            start += 1

        while array[end] > pivot:
            end -= 1

        if(start < end):
            array[start], array[end] = array[end], array[start]

    array[end], array[pivot_index] = array[pivot_index], array[end]

    return end

def quick_sort(start, end, array):
    
    if (start < end):
        
        
        p = partition(start, end, array)

        quick_sort(start, p - 1, array)
        quick_sort(p + 1, end, array)
       
        print(array)

array = [6,3,11,9,12,2,8,15,18,10,7,14]
quick_sort(0, len(array) - 1, array)
  
print(f'Sorted array: {array}')