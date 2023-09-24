import os
name = "799. Champagne Tower"

obsidian = False
create_cpp = True
create_python = False
create_javascript = False
obsidian_path = "E:\onedrive\obsidian"
root_path = os.path.abspath(os.path.dirname(__file__))
obsidian_cpp_path = os.path.join(obsidian_path, 'cpp')
obsidian_leetcode_path = os.path.join(obsidian_cpp_path, 'leetcode')
leetcode_path = os.path.join(root_path, 'leetcode')


def file_format_writer(leetcode):
    companies_str = ''
    return '''
        /*
            Leetcode Link           : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
            Company Tags            : {}
        */

        /*
            references:
            
        */

        //Approach-1 (Using Greedy approach similar to Jump Game-II)
        //TC : O(n)
        //SC : O(1)
    '''


if not obsidian_path:
    print("Obsidian Path does not exist")
    exit(1)

if not obsidian_leetcode_path:
    # create path
    os.mkdir(obsidian_cpp_path)
    os.mkdir(obsidian_leetcode_path)


parts = name.split('.')
p1 = "_leetcode_" + parts[0]
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
                f.write("")
        else:
            print("File already exists")

for x in [python, cpp, javascript]:
    print(x)
