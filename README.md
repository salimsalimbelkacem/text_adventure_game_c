# text adventure game in c
I always wanted to make one in c, i love this kind of challenge
and i always loved writing c code, tho string manipulation is
a pain in the ear. :P

for the moment it is pretty empty, but i can ilustrate
my progress with a todo list:
- [ ] game system
    - [x] map system
    - [ ] inventory system
    - [ ] npc system
    - [ ] dialogue system
    - [x] game api
- [ ] parse system
    - [ ] string tokenizing (is not good at all for the moment)
    - [x] command mapping
    - [x] handling system
    - [x] parse api
- [ ] save system
- [ ] game data storage system
    - [ ] reading and interpreting
    - [ ] map and map info storage
    - [ ] npc and npc dialogue storage
    - [ ] items and items info storage
- [ ] http API
- [ ] front end

# front end / http api
for the front end i can implement an http API and make a web
front end or a simple cli client, kinda overkill tbh but may be
fun idk.

OR i can just have a simple io system that is hardcoded to the
game which is kinda boring but fair.

> if http api, i should have some sort of database to store each
individual player progress, or a way to store and map player progress
with their clients and correctly interact and with the game engin.

# game data storage system
i thought about implementing a doom-like data system where only
the engin is hardcoded in the game and the rest of the data is inside
a zip file, like epubs or pdfs or wads.
