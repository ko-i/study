fn main() {
    let v = vec![3, 4, 20, 12, 8];

    let mut iterator = v.iter();

    while let Some(ele) = iterator.next() {
        println!("{:?}", ele);
    }
}