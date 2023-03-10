Name: picviewer
Version: 0.0.1
Release: 1
Summary: Example application for CI testing
BuildArch: x86_64
License: Closed Source
Source0: src.tar.gz

%description
Example application for CI testing.

%prep
%setup -q

%build

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
cp picviewer $RPM_BUILD_ROOT/%{_bindir}/picviewer
chmod +x $RPM_BUILD_ROOT/%{_bindir}/picviewer

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_bindir}/picviewer

%changelog