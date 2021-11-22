Name:           nemo-gst-interfaces
Summary:        Nemo mobile GStreamer interfaces
Version:        1.0.0
Release:        1
License:        LGPLv2+
URL:            https://github.com/sailfishos/nemo-gst-interfaces/
Source0:        %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(gstreamer-plugins-base-1.0)

%description
Nemo mobile GStreamer interfaces

%package -n nemo-gstreamer1.0-interfaces
Summary: gstreamer interface used for video rendering

%description -n nemo-gstreamer1.0-interfaces
%{summary}

%post -n nemo-gstreamer1.0-interfaces -p /sbin/ldconfig
%postun -n nemo-gstreamer1.0-interfaces -p /sbin/ldconfig

%package -n nemo-gstreamer1.0-interfaces-devel
Summary: gstreamer interface used for video rendering devel package
Requires:  nemo-gstreamer1.0-interfaces = %{version}-%{release}

%description -n nemo-gstreamer1.0-interfaces-devel
%{summary}

%post -n nemo-gstreamer1.0-interfaces-devel -p /sbin/ldconfig
%postun -n nemo-gstreamer1.0-interfaces-devel -p /sbin/ldconfig

%prep
%setup -q

%build
%autogen
%configure VERSION="`echo %{version} | sed 's/+.*//'`" --disable-static
%make_build

%install
%make_install
rm -f %{buildroot}/%{_libdir}/*.la

%files -n nemo-gstreamer1.0-interfaces
%defattr(-,root,root,-)
%license COPYING
%{_libdir}/libgstnemointerfaces-1.0.so.*
%{_libdir}/libgstnemometa-1.0.so.*

%files -n nemo-gstreamer1.0-interfaces-devel
%defattr(-,root,root,-)
%{_libdir}/libgstnemointerfaces-1.0.so
%{_libdir}/libgstnemometa-1.0.so
%{_libdir}/pkgconfig/*-1.0.pc
%{_includedir}/gstreamer-1.0/gst/interfaces/nemoeglimagememory.h
%{_includedir}/gstreamer-1.0/gst/interfaces/nemovideotexture.h
%{_includedir}/gstreamer-1.0/gst/meta/nemometa.h
