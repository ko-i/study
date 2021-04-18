fn main() {
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);

    println!("{:?}", vec.len());
    println!("{:?}", vec[0]);
    println!("{:?}", vec.pop());
    println!("{:?}", vec.len());

    vec[0] = 7;
    println!("{:?}", vec[0]);
    println!("{:?}", vec.get(0));
    println!("{:?}", vec.get(10));

    vec.extend([1, 2, 3].iter().cloned());
    println!("{:?}", vec);
    println!("{:?}", vec.get(0..2));

    let mut vec2 = vec![4, 5, 6];
    vec.append(&mut vec2);
    println!("{:?}", vec);
    println!("{:?}", vec2);

    let slice = [1, 2, 3, 4, 5, 6, 7];
    vec.copy_from_slice(&slice);
    println!("{:?}", slice);
    println!("{:?}", vec);

    let slice = [4, 3, 2, 1];
    vec.clone_from_slice(&slice);
    println!("{:?}", vec);
    println!("{:?}", slice);
}