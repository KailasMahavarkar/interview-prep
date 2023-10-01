
testcase = """[[1,2],[2,3],[5],[0],[5],[],[]]"""


def inverse_brackets(str="", inverseQuotes=False):
    type = ''
    for x in str:
        if x == '{':
            type = '{'
            break
        elif x == '[':
            type = '['
            break

    if (type == '['):
        str = str.replace('[', '{').replace(']', "}").strip()
    if (type == '{'):
        str = str.replace('{', '[').replace('}', "]").strip()

    if inverseQuotes:
        if str.find('"') != -1:
            return str.replace('"', "'").strip()
        else:
            return str.replace("'", '"').strip()

    return str.strip()


print(inverse_brackets(
    testcase, inverseQuotes=True
))
