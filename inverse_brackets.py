
testcase = """[[0,0,0],[1,1,0],[1,1,0]]"""

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
