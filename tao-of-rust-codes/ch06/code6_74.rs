fn main() {
    let arr1 = [1, 2, 3, 4, 5];
    let c1 = arr1.iter().map(|x| 2 * x).collect::<Vec<i32>>();

    println!("{:?}", arr1);
    println!("{:?}", c1);

    let arr2 = ["1", "2", "3", "4", "h"];
    let c2 = arr2.iter().filter_map(|x| x.parse().ok()).collect::<Vec<i32>>();
    println!("{:?}", arr2);
    println!("{:?}", c2);

    let arr3 = ['a', 'b', 'c'];
    for (idx, val) in arr3.iter().enumerate() {
        println!("idx: {:?}, val: {}", idx, val);
    }
}