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


testcase = """[[-10,-8],[-4,7],[-5,0],[-6,-4],[1,7],[6,10],[8,9],[9,10]]"""

print(inverse_brackets(testcase))
