// use std::cmp::Ordering;

fn main() {
    let result = 1.0.partial_cmp(&2.0);
    println!("{:?}", result);

    let result = 1.cmp(&1);
    println!("{:?}", result);

    let result = "abc".partial_cmp(&"Abc");
    println!("{:?}", result);

    let mut v: [f32; 5] = [5.0, 4.1, 1.2, 3.4, 2.5];
    v.sort_by(|a, b| a.partial_cmp(b).unwrap());
    println!("{:?}", v);

    v.sort_by(|a, b| b.partial_cmp(a).unwrap());
    println!("{:?}", v);
}