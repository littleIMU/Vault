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

### Ques

- [x] How to compile vim with python3 support?  enter vim source folder and exercute the following `./configure --enable-pythoninterp --enable-python3interp` ✅ 2022-11-29
- [x] install specific version of vim plugin. ex. Plug 'Valloric/YouCompleteMe', { 'commit':'d98f896' } ✅ 2022-11-29

---

[Vim as an IDE](https://blog.jez.io/vim-as-an-ide/)
[https://github.com/jez/vim-as-an-ide](https://github.com/jez/vim-as-an-ide)

Plugin shortcut:

`\b`                     : split pane view that shows your functions, variables, and other identifiers
c-p                    : bring up a list of files
c-t                    : nerdtree
c-f                    : nerdtreefind
`<leader>n`            : nerdtreefocus
`<leader>h`            : switch hlsearch
`<leader>r`            : ranger
c-hjkl                 : move line or letter in normal mode
s-hjkl                 : move selected content in visual mode
`<ctrl-w>+v`           : opens a new vertical split
`<ctrl-w>+s`           : opens a new horizontal split
`<ctrl-w>+c`           : closes a window
`<ctrl-w>+o`           : makes current window the only one on screen and closes other windows
`<ctrl-w>+h/j/k/l`     : moves the cursor to left/bottom/top/right
`<ctrl-]>`                    : ctag next
`<ctrl-t>`                    : ctag jump back from the definition 
`<ctrl-w-]>`                    : open the definition in a horizontal split 
`:ts <tag-name>`          : list the tags that mach <tag_name>
`:tn`                        : jump to the nex matching tag
`:tp`                        : jump to the previous matching tag
`<leader>fw`           : find in workplace
`<leader>fd`           : find in document
`<leader>n`            : toggle ycm hints
: savesession
: opensession
!ctags -r . 
`<leader>fa`           : cscopefindinteractive
`<leader>l`            : toggle cscope
c-o, c-i               : next or previous cursor position
`gaip-<direction>:`    : align around the last occurrences, and place the column right next to the preceding token without margin
gx		       : open link in broswer
`<leader><leader>w`    : easymotion find word after the cursor
`<leader><leader>b`    : easymotion find word before the cursor
`<leader><leader>l`    : easymotion move to line
`<Ctrl-w> +/-`             : increase/decease height (ex. `29<Ctrl-w>+`)
`<Ctrl-w> >/<`             : increase/decease width (ex. `29<Ctrl-w><`)
`<Ctrl-w> =`             : resize all windows to equal dimensions 
`/\<your_exact_word\>` : search for the exact word
`/<word>\c`            : case-insensitive search for the word
`/<word>\c`            : case-sensitive search for the word
`:1,10g/^$/d`          : remove blank lines between line 1 and 10
`1,10s/\#/:/gc`        : find and replace special symbol hash with comfirm flag from line 1 to 10
`vert diffsplit <diff_file>`   : split the vim editor and diff compare files
`diffoff`         : close diff mode
`<Ctrl-a>` : increase the number where cursor is on by 1
`gv`: re-select the previously selected area
`%s/\<./\u&/g`: change the first letter of a word in entire file
`gu`: change seleted words to lowercase

folding c
zf#j creates a fold from the cursor down # lines.
zf/ string creates a fold from the cursor to string .
zj moves the cursor to the next fold.
zk moves the cursor to the previous fold.
za toggle a fold at the cursor.
zo opens a fold at the cursor.
zO opens all folds at the cursor.
zc closes a fold under cursor. 
zm increases the foldlevel by one.
zM closes all open folds.
zr decreases the foldlevel by one.
zR decreases the foldlevel to zero -- all folds will be open.
zd deletes the fold at the cursor.
zE deletes all folds.
`[`z move to start of open fold.
`]`z move to end of open fold.

## ack silver search
ack silver search, ex: `ACK! --ackmate --md <pattern> -C 1` 
?    a quick summary of these keys, repeat to close
o    to open (same as Enter)
O    to open and close the quickfix window
go   to preview file, open but maintain focus on ack.vim results
t    to open in new tab
T    to open in new tab without moving to it
h    to open in horizontal split
H    to open in horizontal split, keeping focus on the results
v    to open in vertical split
gv   to open in vertical split, keeping focus on the results
q    to close the quickfix window

# make a sequence

## use macro
[Source](https://vim.fandom.com/wiki/Increasing_or_decreasing_numbers#Making_a_list)
type the line you want to repeat, e.g.
`101 This is an item.`
In normal mode, enter the following to record a macro nito the `a` register (type the character shown, without pressing Enter). This macro yank the current line, then pastes it below, then increments the number.
```
qa
Y   # in my vim config, it is YY
p
Ctrl-A
q
```
Now type `15@a` to perform the macro 15 times.
Later, you might insert a new item after #102. Now you need to renumber the following items (the new item will be 103, so the old 103 has to be incremented, as does 104, and so on. That can be done using `:.,$g/^\d/exe "normal! \<C-a>"`
## use programming
```
:for i in range(1,10) | put ='192.168.0.'.i | endfor
```
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
let g:ycm_enable_inlay_hin
```

#  simple templates

```sh
## source https://www.geeksforgeeks.org/creating-a-c-template-in-vim-in-linux/
# create templates folder
cd ~/.vim
mkdir templates && cd templates
sudo vim skeleton.cpp
# add following line in .vimrc file
:autocmd BufNewFile  *.c 0r ~/vim/templates/skeleton.c 
```

# advanced templates

using vim [plugin](https://github.com/tibabit/vim-templates)