#[must_use]
pub enum Result<T, E> {
    Ok(T),
    Err(E),
}