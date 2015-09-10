;; Start maximized
(custom-set-variables
 '(initial-frame-alist (quote ((fullscreen . maximized)))))

;; Disable menu bar
(menu-bar-mode -1)

;; Disable tool bar
(tool-bar-mode -1)

;; Set face attribute
(set-face-attribute 'default nil :height 92)

;; Some irony-mode configuration from github.com/Sarcasm/irony-mode
(add-hook 'c++-mode-hook 'irony-mode)
(add-hook 'c-mode-hook 'irony-mode)
(add-hook 'objc-mode-hook 'irony-mode)

;; replace the `completion-at-point' and `complete-symbol' bindings in
;; irony-mode's buffers by irony-mode's function
(defun my-irony-mode-hook ()
  (define-key irony-mode-map [remap completion-at-point]
    'irony-completion-at-point-async)
  (define-key irony-mode-map [remap complete-symbol]
    'irony-completion-at-point-async))
(add-hook 'irony-mode-hook 'my-irony-mode-hook)
(add-hook 'irony-mode-hook 'irony-cdb-autosetup-compile-options)

;; Set company-mode for all buffers
(add-hook 'after-init-hook 'global-company-mode)

;; Add company-irony, company-c-headers, and company-irony-c-headers
;; to company backends
;; Load with `irony-mode` as a grouped backend
(eval-after-load 'company
  '(add-to-list
    'company-backends '(company-irony-c-headers company-c-headers company-irony)))

;; Bind for company-complete
(global-set-key (kbd "C-.") 'company-complete)

;; Copy line, use C-y to paste it later
(global-set-key (kbd "\C-c\C-d") "\C-a\C- \C-n\M-w")

;; Open file selected in new buffer
(global-set-key (kbd "C-x p") 'ff-find-other-file)

;; Shortcuts for navigating windows based on geometry
(global-set-key (kbd "C-x <up>") 'windmove-up)
(global-set-key (kbd "C-x <down>") 'windmove-down)
(global-set-key (kbd "C-x <left>") 'windmove-left)
(global-set-key (kbd "C-x <right>") 'windmove-right)

(require 'package)
(add-to-list 'package-archives '("melpa" . "http://melpa.milkbox.net/packages/"))
(package-initialize)
(add-hook 'prog-mode-hook 'linum-mode)
(add-to-list 'custom-theme-load-path "~/.emacs.d/themes")

(setq-default tab-width 3)
(defvaralias 'c-basic-offset 'tab-width)
(defvaralias 'cperl-indent-level 'tab-width)
(smart-tabs-insinuate 'c 'c++ 'java 'javascript 'python)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes (quote (jazz)))
 '(custom-safe-themes
	(quote
	 ("66c39acbff18daeeff5177ceeff2eb8b4d7cd0e2fc5fcb68cf39a6dafdc7a453" default)))
 '(inhibit-startup-screen t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
