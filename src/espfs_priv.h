#pragma once

#include <stddef.h>
#include "sdkconfig.h"
#include "esp_partition.h"
#include "espfsformat.h"

struct EspFs {
	const void *memAddr;
#if CONFIG_IDF_TARGET_ESP32 == 1
	spi_flash_mmap_handle_t mmapHandle;
#endif
	size_t length;
	size_t numFiles;
};

struct EspFsFile {
	EspFsHeader *header;
	char decompressor;
	int32_t posDecomp;
	char *posStart;
	char *posComp;
	void *decompData;
};