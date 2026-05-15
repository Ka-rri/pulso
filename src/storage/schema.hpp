#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

namespace pulso::storage {

/**
 * @brief Crea las tablas e índices necesarios en la base de datos.
 *
 * Inicializa el esquema de la base de datos SQLite creando la tabla
 * `snapshots` y el índice `idx_snapshots_timestamp` si no existen.
 * La función es idempotente: puede llamarse varias veces sin errores.
 *
 * @param db Referencia a la base de datos SQLite abierta.
 */
void inicializarEsquema(SQLite::Database& db);

} 