//Ethan Tarlov
//HW4.fs
//2/13/22

//Exercise 1
let CylinderVolume ((radius, height) : float * float) =
height * System.Math.PI * radius * radius

let maxCylinderVolume lst =
    let rec recMax maxVol items =
        match items with
        | [] -> maxVol
        | h :: t -> let volume = CylinderVolume h
                    if maxVol < volume 
                    then recMax volume t 
                    else recMax maxVol t
    recMax 3.0 lst 
// Exercise 2
let rec mem list dupes =
  match list with
  | [] -> false
  | head :: tail ->
    if dupes = head 
        then true 
    else mem tail dupes

let elimDuplicates list1 =
  let rec removeduprec list1 list2 =
    match list1 with
    | [] -> list2
    | head :: tail when mem list2 head = false -> removeduprec tail (list2 @ [head])
    | h :: t -> removeduprec t list2
  removeduprec list1 []
  
// Exercise 3

type BST =
    | Empty
    | TreeNode of int * BST * BST

let rec insert value tree = // insert
    match tree with
        | Empty -> TreeNode(value, Empty, Empty)
        | TreeNode(curr, left, right) -> 
            if curr = value then tree
            else if curr > value then TreeNode(curr, (insert value left), right)
            else TreeNode(curr, left, (insert value right))

let rec search value tree = // search
    match tree with
        | Empty -> false
        | TreeNode(curr, left, right) ->
            if value < curr
                then search value left
            else if value = curr
                then true
            else search value right;;

let rec count func tree = // count
    match tree with
        | Empty -> 0
        | TreeNode(curr, left, right) ->
            if func curr
                then 1 + (count func left) + (count func right)
            else (count func left) + (count func right) 

let rec evenCount tree = // even count
    count (fun curr -> curr%2 = 0) tree