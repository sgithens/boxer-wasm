
(defun setup-boxer ()
  (let ((project-dir #P"/boxerdata/boxer-sunrise/"))
    (setf asdf:*central-registry*
      (list* '*default-pathname-defaults*
              project-dir
              asdf:*central-registry*))
    (ql:quickload :boxer-sunrise-threejs)))
