fn main() {
    let v: Vec<i32> = (1..4).chain(vec![10, 20, 30]).collect();
    println!("{:?}", v);

    let v: Vec<i32> = (1..4).chain(vec![10, 20, 30]).rev().collect();
    println!("{:?}", v);
}