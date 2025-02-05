
MAKE = make

.PHONY: all
all:
	$(MAKE) -j -C musl-1.1.18 all
	$(MAKE) -j -C asp3_dcre all
	$(MAKE) -j -C mbedtls-2.16.1 all
	$(MAKE) -j -C wolfssl-3.15.7 all
	$(MAKE) -j -C zlib-1.2.11 all
	$(MAKE) -j -C curl-7.57.0 all
	$(MAKE) -j -C azure_iothub all
	$(MAKE) -j -C app_iothub_client all

.PHONY: clean
clean:
	$(MAKE) -j -C musl-1.1.18 clean
	$(MAKE) -j -C asp3_dcre clean
	$(MAKE) -j -C mbedtls-2.16.1 clean
	$(MAKE) -j -C wolfssl-3.15.7 clean
	$(MAKE) -j -C zlib-1.2.11 clean
	$(MAKE) -j -C curl-7.57.0 clean
	$(MAKE) -j -C azure_iothub clean
	$(MAKE) -j -C app_iothub_client clean

.PHONY: realclean
realclean:
	$(MAKE) -j -C musl-1.1.18 clean
	$(MAKE) -j -C asp3_dcre realclean
	$(MAKE) -j -C mbedtls-2.16.1 clean
	$(MAKE) -j -C wolfssl-3.15.7 clean
	$(MAKE) -j -C zlib-1.2.11 clean
	$(MAKE) -j -C curl-7.57.0 clean
	$(MAKE) -j -C azure_iothub clean
	$(MAKE) -j -C app_iothub_client realclean
