---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: 
link_course: 
link_notes: 
---

[Vim as an IDE](https://blog.jez.io/vim-as-an-ide/)

[https://github.com/jez/vim-as-an-ide](https://github.com/jez/vim-as-an-ide)

Plugin shortcut:

\b: split pane view that shows your functions, variables, and other identifiers 

C-p: bring up a list of files

C-t: nerdtree

C-f: NerdtreeFind

<leader>n: nerdtreeFocus

<leader>h: switch hlsearch 

<leader>f: ranger

C-hjkl: move line or letter in normal mode

S-hjkl: move selected content in visual mode

:AV :  move to head file

<Ctrl-W>+v       # Opens a new vertical split
<Ctrl-W>+s       # Opens a new horizontal split
<Ctrl-W>+c       # Closes a window
<Ctrl-W>+o       # Makes current window the only one on screen and closes other windows
<Ctrl-W>+h/j/k/l # Moves the cursor to left/bottom/top/right

C-]: ctag next

<leader>fw: find in workplace

<leader>fd: find in document

<leader>n: toggle YCM hints

:savesession

:opensession

!ctags -R . 

`<leader>fa`: Cscopefindinteractive

`<leader>l` : toggle Cscope

`/\<your_exact_word\>`: search for the exact word

C-o, C-i, next or previous cursor position

# ctags

```cpp
sudo apt install ctags
ctag -R <Direc Path>
// set tags+=<Direc_path> in ~/.vimrc 
```

# auto completion

```cpp
Plug 'Valloric/YouCompleteMe' 

//after install language package
enter ~/.vim/plugged/Youcompleteme
python3 install.py <language>
or 
python3 install.py -a

"install language in .vim/plugged/youcompleteme by install.py <language>
" https://github.com/ycm-core/YouCompleteMe
" sudo apt install mono-complete golang nodejs openjdk-17-jdk openjdk-17-jre npm
" The following additional language support options are available:
"C# support: install Mono and add --cs-completer when calling install.py.
"Go support: install Go and add --go-completer when calling install.py.
"JavaScript and TypeScript support: install Node.js and npm and add --ts-completer when calling install.py.
"Rust support: add --rust-completer when calling install.py.
"Java support: install JDK 17 and add --java-completer when calling install.py.

//setting in .vimrc
let g:ycm_enable_semantic_highlighting=1
let g:ycm_enable_inlay_hints=1
```