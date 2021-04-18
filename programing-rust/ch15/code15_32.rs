fn main() {
    let mut v: Vec<i32> = (0..5).map(|i| 1 << i).collect();

    v.extend(&[31, 57, 99, 163]);

    println!("{:?}", v);
}