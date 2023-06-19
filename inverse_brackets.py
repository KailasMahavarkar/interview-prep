def inverse_brackets(str=""):
    type = ''
    for x in str:
        if x == '{':
            type = '{'
            break
        elif x == '[':
            type = '['
            break

    if (type == '['):
        return str.replace('[', '{').replace(']', "}").strip()
    if (type == '{'):
        return str.replace('{', '[').replace('}', "]").strip()
    return str.strip()


testcase = """[[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]"""

print(inverse_brackets(testcase))
