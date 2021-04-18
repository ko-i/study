fn main() {
    let mut vec = Vec::with_capacity(10);
    for i in 1..10 {
        vec.push(i);
    }

    vec.truncate(0);
    println!("{:?}", vec);
    println!("{:?}", vec.capacity());

    for i in 1..10 {
        vec.push(i);
    }

    vec.clear();
    println!("{:?}", vec.capacity());

    vec.shrink_to_fit();
    println!("{:?}", vec.capacity());

    for i in 0..10 {
        vec.push(i);
        println!("{:?}", vec.capacity());
    }

}