# Entries
## 12/10/2025
### Description:
Worked on implementing the methods of `tree.h` in `tree.cpp`. I've somehow gone from writing 0 BFS methods to like 3 of them in one night, which is kind of insane considering I have no idea if they even work yet or not.

### Bugs, Issues, Problems
The code is entirely untested. I haven't run it yet, but I am very afraid that it will not work. However, once I implement the rest of the necessary methods, I will test the code with different runs and compare it against the output guide.
Additionally, I believe `addNode` has the potential to cause a segmentation fault if it tries to add to an empty tree.

## 12/11/2025
### Description:
Worked on fixing up some of the potential bugs in `tree.cpp`, specifically in adding a new node. Additionally, I have implemented `printAll()` using... drummroll please... BFS! I hope it all somehow magically works!

### Bugs, Issues, Problems
The code still remains untested. I am mainly going off of tracing it in my mind with ideal and edge cases as I go along.

---

# Commits
## 1 - 12/10/2025

Created `this developer_log.md` file!

Created `tree.cpp`:
- Implemented `Node()` constructor
- Implemented `Tree()` constructor
- Implemented `createRoot()`
- Implemented `addNode()`
- Implemented `findNode()`
- Implemented `~Tree()` destructor

## 2 - 12/11/2025

Correctly added `developer_log.md` and `CMakeLists.txt` to the git repo this time. Oops!

Modified `tree.cpp`:
- Implemented `printAll()`
- Fixed a potential bug where `addNode()` would try to set a member of `nullptr` to a node if the tree was empty.