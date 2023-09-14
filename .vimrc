"Don't try to be vi compatible

:set nocompatible

"Turn on syntax highlighting
:syntax on

"Show line numbers
:set nu

"Show relative numbers when normal mode
:augroup numbertoggle
:  autocmd!
:  autocmd BufEnter,FocusGained,InsertLeave,WinEnter * if &nu && mode() != "i" | set rnu   | endif
:  autocmd BufLeave,FocusLost,InsertEnter,WinLeave   * if &nu                  | set nornu | endif
:augroup END

"Incremental search matches 
":noh to unhighlight
"n or N to jump to the next or previous search (or Ctrl-t Ctrl-g)
":%s/<find>/<replace>/g (or gc)
:set hlsearch
:set incsearch

"Autopairs
inoremap { {}<Esc>ha
inoremap ( ()<Esc>ha
inoremap [ []<Esc>ha
inoremap " ""<Esc>ha
inoremap ' ''<Esc>ha
inoremap ` ``<Esc>ha

"Indent"
:set autoindent
:set smartindent
