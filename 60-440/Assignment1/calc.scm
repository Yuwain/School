#| Written by: Jeremy High
   Student ID: 103306452
   Written on: September 20th, 2013 |#

;A left-associative calculator for addition and subtraction
(define (calculator expr)
  (cond ((number? expr)
         expr)
        ((eq? (length expr) 1)
         (car expr))
        (else
         (let ((head ((lambda (expr)
                        (let ((op (eval (cadr expr)))
                              (num1 (calculator (car expr)))
                              (num2 (calculator (caddr expr))))
                          (op num1 num2))) expr))
               (tail (cdddr expr)))
           (calculator (cons head tail))))))
