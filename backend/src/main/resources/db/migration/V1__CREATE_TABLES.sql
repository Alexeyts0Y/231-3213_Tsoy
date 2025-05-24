CREATE TABLE bikes (
    id BIGSERIAL PRIMARY KEY,
    image_url VARCHAR(255) NOT NULL,
    name VARCHAR(255) NOT NULL,
    description VARCHAR(255) NOT NULL,
    brand VARCHAR(255),
    price BIGINT,
    weight INT,
    color VARCHAR(255)
);