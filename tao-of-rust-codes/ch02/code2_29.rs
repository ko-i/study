fn main() {
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    assert_eq!(&[1, 2, 3, 4, 5], &arr);
    assert_eq!([2, 3, 4, 5], &arr[1..]);
    assert_eq!(&5, &arr.len());
    assert_eq!(&false, &arr.is_empty());

    let arr = &mut [1, 2, 3];
    arr[1] = 7;
    assert_eq!(&[1, 7, 3], arr);

    let vec = vec![1, 2, 3];
    assert_eq!(&vec[..], [1, 2, 3]);
}