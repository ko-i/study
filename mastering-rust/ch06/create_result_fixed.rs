fn main() {
    let _my_result: Result<_, ()> = Ok(64);
    let _my_result = Ok::<_, ()>(64);

    let _my_err = Err::<(), f32>(345.3);
    let _other_err: Result<bool, String> = Err("Wait, what ?".to_string());
}