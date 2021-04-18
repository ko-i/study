fn main() {
    let mut vec = vec![1, 2, 3];
    vec.insert(1, 4);
    println!("{:?}", vec);

    vec.insert(4, 5);
    println!("{:?}", vec);

    vec.insert(8, 8);
    println!("{:?}", vec);
}