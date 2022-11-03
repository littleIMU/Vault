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

# Example

In Linux, the config file is in ~/ called *.emacs*

[Introduction to Emacs Org Mode](https://www.youtube.com/watch?v=ZMEcb2rpauU)

[test.org](emacs/test.org)

# Basic Commands

switch window: C-x o

create/only window: C-x 1

quit M-x: C-g

cons

evil-normal-mode:

- shift and indent: >, <, C-i
- visual block: C-v + S-i
- Redo & undo: \C-r, up

org-mode:

block template: C-c C-,

# Useful Commands

C-c C-e h o: generate a html file and open it

C-c C-e o: generate a pdf file

M-x package-list-packages: list all third packages 

M-x package-install RET: install a specified package

C-m: RET

M-Right: decrease head level

M-Left

M-Up: move head 

M-Down:

# Installation using melpa

```cpp
;; Set up package.el to work with MELPA
(require 'package)
(add-to-list 'package-archives
             '("melpa" . "https://melpa.org/packages/"))
(package-initialize)
(package-refresh-contents)

(unless (package-installed-p 'evil)
  (package-install 'evil))
(unless (package-installed-p 'evil-collection)
  (package-install 'evil-collection))
(unless (package-installed-p 'org-preview-html)
  (package-install 'org-preview-html))
(unless (package-installed-p 'org-babel-eval-in-repl)
  (package-install 'org-babel-eval-in-repl))
(unless (package-installed-p 'ob-mermaid)
  (package-install 'ob-mermaid))
```

# Packages

## emacs evil package

### ****Manual installation****

Evil lives in a git repository. To download Evil, do:

`git clone --depth 1 https://github.com/emacs-evil/evil.git`

Then add the following lines to your Emacs init file:

`(add-to-list 'load-path "path/to/evil")
(require 'evil)
(evil-mode 1)`

Ensure that your replace `path/to/evil` with the actual path to where you cloned Evil.

### keybindings to vim

[Keymaps - Evil 1.14.0 documentation](https://evil.readthedocs.io/en/latest/keymaps.html)

## emacs org-mode

## emacs

M-x o-pre-m

Note that it is updated after you save the .org file 

## emacs org-babel-eval-in-repl

add the following in *.emacs* after installing the evaluation package

```cpp
(org-babel-do-load-languages
 'org-babel-load-languages
 '((python . t)))
(org-babel-do-load-languages
 'org-babel-load-languages
 '((C . t)))
```

## Orb-mermaid

[https://github.com/arnm/ob-mermaid](https://github.com/arnm/ob-mermaid)

[GitHub - mermaidjs/mermaid.cli: Development has been moved to https://github.com/mermaid-js/mermaid-cli](https://github.com/mermaidjs/mermaid.cli)

mmdc is in “`./node_modules/.bin/mmdc`”

## Org-brain

to be continued …

## Latex preview

to be continued …

## Use package

[use-package/use-package.org at master · jwiegley/use-package](https://github.com/jwiegley/use-package/blob/master/use-package.org)