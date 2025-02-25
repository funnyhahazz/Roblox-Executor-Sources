#pragma once

#include <string_view>
#include <functional>
#include <variant>

namespace pepp
{
	struct ModuleImportData_t
	{
		std::uint32_t								module_name_rva;
		std::string									module_name;
		std::uint32_t								import_name_rva;
		std::variant<std::string, std::uint64_t>	import_variant;
		std::uint32_t								import_rva;
		bool										ordinal;
	};

	static constexpr auto IMPORT_ORDINAL_FLAG_32 = IMAGE_ORDINAL_FLAG32;
	static constexpr auto IMPORT_ORDINAL_FLAG_64 = IMAGE_ORDINAL_FLAG64;

	template<unsigned int bitsize>
	class ImportDirectory : pepp::msc::NonCopyable
	{
		friend class Image<32>;
		friend class Image<64>;

		Image<bitsize>*							m_image;
		detail::Image_t<>::ImportDescriptor_t*	m_base;
		detail::Image_t<>::ImportAddressTable_t m_iat_base;
	public:
		ImportDirectory() = default;

		bool importsModule(std::string_view module, std::uint32_t* name_rva = nullptr) const;
		bool hasModuleImport(std::string_view module, std::string_view import, std::uint32_t* rva = nullptr) const;
		void addModuleImport(std::string_view module, std::string_view import, std::uint32_t* rva = nullptr);
		void addModuleImports(std::string_view module, std::initializer_list<std::string_view> imports, std::uint32_t* rva = nullptr);
		void traverseImports(const std::function<void(ModuleImportData_t*)>& cb_func);

		void setCharacteristics(std::uint32_t chrs) {
			m_base->Characteristics = chrs;
		}

		std::uint32_t getCharacteristics() const {
			return m_base->Characteristics;
		}
		
		void setTimeDateStamp(std::uint32_t TimeDateStamp) {
			m_base->TimeDateStamp = TimeDateStamp;
		}

		std::uint32_t getTimeDateStamp() const {
			return m_base->TimeDateStamp;
		}

		//! Util
		template<typename T>
		bool isImportOrdinal(T ord) const requires pepp::msc::MemoryAddress<T> {
			if constexpr (bitsize == 64)
				return (ord & IMPORT_ORDINAL_FLAG_64) != 0;
			return (ord & IMPORT_ORDINAL_FLAG_32) != 0;
		}

		void getIATOffsets(std::uint32_t& begin, std::uint32_t& end) noexcept;
		void getIATRvas(std::uint32_t begin, std::uint32_t& end) noexcept;

	private:
		//! Setup the directory
		void _setup(Image<bitsize>* image) {
			m_image = image;
			m_base = reinterpret_cast<decltype(m_base)>(
				&image->base()[image->getPEHdr().rvaToOffset(
					image->getPEHdr().getOptionalHdr().getDataDir(DIRECTORY_ENTRY_IMPORT).VirtualAddress)]);		
			m_iat_base = reinterpret_cast<decltype(m_iat_base)>(
				&image->base()[image->getPEHdr().rvaToOffset(
					image->getPEHdr().getOptionalHdr().getDataDir(DIRECTORY_ENTRY_IAT).VirtualAddress)]);
		}
	};
}