let rec fact x = 
    if x < 1 then 1 
    else x * fact (x - 1);;

let rec map f values =
    match values with 
        | [] -> []
        | hd::tl -> (f hd) :: map f tl
map (fun x -> x * 3) [1..8]

type Expression = 
  | X 
  | Const of float 
  | Neg of Expression 
  | Add of Expression * Expression 
  | Sub of Expression * Expression 
  | Mul of Expression * Expression 
  | Div of Expression * Expression 
  | Pow of Expression * Expression 

Add (Mul (Const 3.0, Pow (X, Const 2.0)), Mul (Const 2.0, X))

let rec deriv (expr: Expression) = 
    match expr with
        | X -> Const 1
        | Const _ -> Const 0
        | Neg u -> Neg(deriv u)
        | Add (u, v) -> Add(deriv u, deriv v)
        | Sub (u, v) -> Sub(deriv u, deriv v)
        | Mul (u, v) -> Add (Mul (u, (deriv v)), Mul(v, (deriv u)))
        | Div (u, v) -> Sub (Mul (u, (deriv v)), Mul(v, (deriv u)))
        | Pow (u,c) -> Mul(Mul (c, Pow(u, Sub(c, Const 1.0))), deriv u)
let testCase = Sub ((Const 10), X)


let rec map f values = 
    match values with  
        | [] -> []
        | hd :: tl -> (f hd) :: (map f tl)

(*
    match "values" with one of these rules:
    - if its exactly, an empty list, return an empty list
    - if you split it into the first element and the rest, 
    then call f with the first element as a parameter, 
    call map with f and the rest as parameters, and
    combine the results of those two by prepending the former to the latter,
    then return that. 

*)

let rec funcName argName1 argName2 argName3 =
  (*return *)  argName1+ argName2 + argName3

  