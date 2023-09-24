
testcase = """[[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]"""

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


print(inverse_brackets(testcase))
