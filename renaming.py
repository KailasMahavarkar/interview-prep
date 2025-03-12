import os
problem_name = "875. Koko Eating Bananas"
platform = 'leetcode'
companies_str = ''
obsidian = False
create_cpp = False
create_python = False
create_javascript = False
obsidian_path = "E:\\onedrive\\obsidian"
root_path = os.path.abspath(os.path.dirname(__file__))
obsidian_cpp_path = os.path.join(obsidian_path, 'cpp')
obsidian_leetcode_path = os.path.join(obsidian_cpp_path, 'leetcode')
leetcode_path = os.path.join(root_path, 'leetcode')

def question_to_link(str):
    if len(str.split(".")) != 2:
        return str

    question = str.split(".")[1]

    dynamic = question.replace(' ', '-').lower()
    if dynamic[0] == '-':
        dynamic = dynamic[1:]

    link = f"https://leetcode.com/problems/{dynamic}/description/"
    return link


def file_format_writer(problem_name, problem_link, companies_str):
    is_leetcode = "leetcode.com" in problem_link

    if is_leetcode:
        p_arr = problem_link.split("problems")[1].split("description")[0].replace("/", "").split("-")
        if (type(p_arr) == list):
            is_valid_leetcode = True
            for x in p_arr:
                if x not in problem_name.lower():
                    is_valid_leetcode = False
                    break
            if not is_valid_leetcode:
                print("Invalid Leetcode Problem")
                exit(1)


    companies_str = companies_str.replace(
        " ", "").replace("|", ",").replace("__", "_")
    return f'''#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : {problem_link}
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

int main(){"{"}

{"}"}

    '''

if platform == 'leetcode':
    problem_link = question_to_link(problem_name)
else:
    problem_link = "None"

if not obsidian_path:
    print("Obsidian Path does not exist")
    exit(1)

if not obsidian_leetcode_path:
    # create path
    os.mkdir(obsidian_cpp_path)
    os.mkdir(obsidian_leetcode_path)


parts = problem_name.split('.')
p1 = f"_{platform}_" + parts[0]
p2 = parts[1].lower().replace(" ", '_').replace("|", "").replace("__", "_")

if obsidian:
    folder = p2 + p1
    if (folder.startswith("_")):
        folder = folder[1:]
        canvas_name = "canvas_" + folder + ".excalidraw"
        note_name = "note_" + folder

        problem_path = os.path.join(obsidian_leetcode_path, folder)
        canvas_path = os.path.join(problem_path, canvas_name)
        note_path = os.path.join(problem_path, note_name)

        if not os.path.exists(problem_path):
            os.mkdir(os.path.join(problem_path))

        # copy content from "excalidraw.md" to new file to canvas_path
        if not os.path.exists(canvas_path):
            # create a local copy of file "excalidraw.md" using os module
            # rename it and move it to location canvas_path
            with open(canvas_path, 'w') as f:
                f.write("")

        # create note
        if not os.path.exists(note_path):
            with open(note_path, 'w') as f:
                f.write("")


python = (p2 + p1 + '.py')[1:]
cpp = (p2 + p1 + '.cpp')[1:]
javascript = (p2 + p1 + '.js')[1:]

for lang in [create_cpp, create_python, create_javascript]:
    if lang:
        check_exists = os.path.exists(os.path.join(leetcode_path, cpp))
        if not check_exists:
            with open(os.path.join(leetcode_path, cpp), 'w') as f:
                text_to_write = file_format_writer(
                    problem_name=problem_name,
                    problem_link=problem_link, companies_str=companies_str)
                if create_cpp:
                    f.write(file_format_writer(
                        problem_name=problem_name,
                        problem_link=problem_link, companies_str=companies_str))
                else:
                    f.write("")
        else:
            print("File already exists")


print(file_format_writer(problem_name=problem_name,problem_link=problem_link, companies_str=companies_str))
for x in [python, cpp, javascript]:
    print(x)
