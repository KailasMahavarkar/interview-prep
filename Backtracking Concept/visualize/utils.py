def compare_array(arr1, arr2):
    if not isinstance(arr1, list) or not isinstance(arr2, list):
        return False
    
    arr1.sort()
    arr2.sort()

    if len(arr1) != len(arr2):
        return False

    for el1, el2 in zip(arr1, arr2):
        if isinstance(el1, list) and isinstance(el2, list):
            if not compare_array(el1, el2):
                return False
        elif el1 != el2:
            return False

    return True